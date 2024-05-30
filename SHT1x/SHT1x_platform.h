 /* Define to prevent recursive inclusion ----------------------------------------*/
#ifndef _SHT1X_PLATFORM_H
#define _SHT1X_PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ---------------------------------------------------------------------*/
#include <stdint.h>
#include "SHT1x.h"


/* Functionality Options --------------------------------------------------------*/
/**
 * @brief  Specify IO Pins of ESP32 connected to SHT1x
 */
#define SHT1x_SCK_GPIO    GPIO_NUM_21
#define SHT1x_DATA_GPIO   GPIO_NUM_22



/**
 ==================================================================================
                               ##### Functions #####                               
 ==================================================================================
 */

/**
 * @brief  Initialize platform device to communicate SHT1x.
 * @retval SHT1x_Result_t
 *         - SHT1x_OK: Operation was successful.
 */
SHT1x_Result_t
SHT1x_Platform_Init(SHT1x_Handler_t *Handler);



#ifdef __cplusplus
}
#endif


#endif
