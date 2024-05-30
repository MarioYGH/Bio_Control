/* Define to prevent recursive inclusion ----------------------------------------*/
#ifndef _SHT1X_CONFIG_H_
#define _SHT1X_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif


/* Configurations ---------------------------------------------------------------*/
/**
 * @brief  Fahrenheit measurement option
 *         - 0: Disable Fahrenheit measurement function
 *         - 1: Enable Fahrenheit measurement function
 */
#define SHT1X_CONFIG_FAHRENHEIT_MEASUREMENT     0

/**
 * @brief  High resolution measurement option
 * @note   By setting this constant to 0, high resolution is selected
 *         - 0: Disable High resolution measurement
 *         - 1: Enable High resolution measurement
 */
#define SHT1X_CONFIG_RESOLUTION_CONTROL         1

/**
 * @brief  Determine how to measure the supply voltage
 *         - 0: The power supply voltage determine by SHT1x_SetPowVoltage function
 *         - 1: The power supply voltage is constant at 3.3 volts
 *         - 2: The power supply voltage is constant at 5 volts
 */
#define SHT1X_CONFIG_POWER_VOLTAGE_CONTROL      2

/**
 * @brief  Internal heater control option
 *         - 0: Disable internal heater control
 *         - 1: Enable internal heater control
 */
#define SHT1X_CONFIG_INTERNAL_HEATER_CONTROL    0



#ifdef __cplusplus
}
#endif

#endif //! _SHT1X_CONFIG_H_
