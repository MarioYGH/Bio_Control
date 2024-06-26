#include <stdio.h>
#include "string.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/timers.h"
#include "esp_now.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_mac.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_http_client.h"
#include "connect_wifi.h"

#define ESP_CHANNEL 1
#define ESP_NOW_PMK "pmk1234567890123"
#define ESP_NOW_LMK "lmk1234567890123"
#define BUTTON GPIO_NUM_18

static uint8_t peer_mac_1[ESP_NOW_ETH_ALEN] = {0xc8, 0xf0, 0x9e, 0xec, 0x0d, 0x18};
static uint8_t peer_mac_2[ESP_NOW_ETH_ALEN] = {0x08, 0xd1, 0xf9, 0xe7, 0x96, 0xb8};

static const char *TAG = "esp_now_init";
static uint8_t count = 0;
static float temperature = 0.0;
static float humidity = 0.0;
char *api_key = "0LCIV8KQ22AXZNR6";

static esp_err_t init_wifi(void)
{
    wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();
    esp_netif_init();
    esp_event_loop_create_default();
    nvs_flash_init();
    esp_wifi_init(&wifi_init_config);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_storage(WIFI_STORAGE_FLASH);
    esp_wifi_start();
    ESP_LOGI(TAG, "wifi init complete");
    return ESP_OK;
}

void recv_cb(const uint8_t *mac_addr, const uint8_t *data, int data_len)
{
ESP_LOGI(TAG, "Data received from: " MACSTR ", Data: %s", MAC2STR(mac_addr), data);
    if (data_len == sizeof(float) * 2) {
        memcpy(&temperature, data, sizeof(float));
        memcpy(&humidity, data + sizeof(float), sizeof(float));
        ESP_LOGI(TAG, "Data received from: " MACSTR ", Temperature: %.2f, Humidity: %.2f", MAC2STR(mac_addr), temperature, humidity);
    } else {
        ESP_LOGW(TAG, "Received invalid data length");
    }
}

void send_cb(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    if (status == ESP_NOW_SEND_SUCCESS) {
        ESP_LOGI(TAG, "ESP_NOW_SEND_SUCCESS");
    } else {
        ESP_LOGW(TAG, "ESP_NOW_SEND_FAIL");
    }
}

static esp_err_t init_esp_now(void)
{
    esp_now_init();
    esp_now_register_recv_cb(recv_cb);
    esp_now_register_send_cb(send_cb);
    esp_now_set_pmk((const uint8_t*)ESP_NOW_PMK);

    ESP_LOGI(TAG, "esp now init complete");
    return ESP_OK;
}

static esp_err_t register_peer(uint8_t *peer_addr)
{
    esp_now_peer_info_t peer_info = {};
    memcpy(peer_info.peer_addr, peer_addr, ESP_NOW_ETH_ALEN);
    peer_info.channel = ESP_CHANNEL;
    peer_info.ifidx = ESP_IF_WIFI_STA;
    memcpy(peer_info.lmk, ESP_NOW_LMK, ESP_NOW_KEY_LEN);
    peer_info.encrypt = true;

    esp_now_add_peer(&peer_info);
    return ESP_OK;
}

static esp_err_t esp_now_send_data(const uint8_t *peer_addr, const uint8_t *data, size_t len)
{
    esp_now_send(peer_addr, data, len);
    return ESP_OK;
}

static void gpio_task_example(void* arg)
{
    uint8_t data1[] = "1";
    uint8_t data2[] = "2";
    uint8_t data3[] = "3";

    while (true)
    {
        if (count > 3)
        {
            count = 1;
        }
        switch (count)
        {
            case 1:
                esp_now_send_data(peer_mac_1, data1, sizeof(data1));
                esp_now_send_data(peer_mac_2, data1, sizeof(data1));
                break;

            case 2:
                esp_now_send_data(peer_mac_1, data2, sizeof(data2));
                esp_now_send_data(peer_mac_2, data2, sizeof(data2));
                break;

            case 3:
                esp_now_send_data(peer_mac_1, data3, sizeof(data3));
                esp_now_send_data(peer_mac_2, data3, sizeof(data3));
                break;

            default:
                break;
        }

        ESP_LOGI(TAG, "Button pressed, count: %d", count);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void isr_handler(void *args)
{
    count++;
}

esp_err_t init_iris()
{
    gpio_config_t io_conf;
    io_conf.pin_bit_mask = (1ULL << BUTTON);
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_NEGEDGE;
    gpio_config(&io_conf);

    // Instalar el servicio de interrupción
    gpio_install_isr_service(0);
    // Asignar la tarea de interrupción al núcleo 0
    gpio_isr_handler_add(BUTTON, isr_handler, NULL);

    return ESP_OK;
}

void send_data_to_thingspeak(void *pvParameters) {
    char *thingspeak_url = "https://api.thingspeak.com";
    char data[] = "/update?api_key=%s&field1=%.2f&field2=%.2f";
    char post_data[200];
    esp_err_t err;

    esp_http_client_config_t config = {
        .url = thingspeak_url,
        .method = HTTP_METHOD_GET,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");

    while (true) {
        snprintf(post_data, sizeof(post_data), data, api_key, temperature, humidity);
        ESP_LOGI(TAG, "post = %s", post_data);
        esp_http_client_set_url(client, post_data);

        err = esp_http_client_perform(client);

        if (err == ESP_OK) {
            int status_code = esp_http_client_get_status_code(client);
            if (status_code == 200) {
                ESP_LOGI(TAG, "Message sent Successfully");
            } else {
                ESP_LOGI(TAG, "Message sent Failed");
                goto exit;
            }
        } else {
            ESP_LOGI(TAG, "Message sent Failed");
            goto exit;
        }
        vTaskDelay(10000 / portTICK_PERIOD_MS); // Aumentar tiempo de espera entre reintentos
    }

exit:
    esp_http_client_cleanup(client);
    vTaskDelete(NULL);
}

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);
    esp_log_level_set("gpio", ESP_LOG_NONE); // Eliminar logs de GPIO

    init_iris();
    ESP_ERROR_CHECK(init_wifi());
    ESP_ERROR_CHECK(init_esp_now());
    ESP_ERROR_CHECK(register_peer(peer_mac_1));
    ESP_ERROR_CHECK(register_peer(peer_mac_2));

    // Crear una tarea para manejar el GPIO y el envío de datos
    xTaskCreatePinnedToCore(gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL, 1); // Núcleo 1

    // Crear la tarea de envío de datos a ThingSpeak en el núcleo 1
    xTaskCreatePinnedToCore(&send_data_to_thingspeak, "send_data_to_thingspeak", 8192, NULL, configMAX_PRIORITIES-1, NULL, 1);
}
