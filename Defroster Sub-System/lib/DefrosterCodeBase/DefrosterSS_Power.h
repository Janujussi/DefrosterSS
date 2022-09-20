/** FILE: DefrosterSS_Power.h
 *
 * @brief Contains all power functions of the defroster sub-system.
*/

#ifndef DEFROSTERSS_POWER_H
#define DEFROSTERSS_POWER_H

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* DefrosterSS Include Files */
#include "DefrosterSS.h"

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

/**
 * @b Description
 * @n
 *  Function for turning fan on.
 *
 * @param[in] fan Fan pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_fanPowerOn(int8_t fan, Temperature_Mode tempMode);

/**
 * @b Description
 * @n
 *  Function for turning heat on.
 *
 * @param[in] heat Heater pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_heatPowerOn(int8_t heat, Temperature_Mode tempMode);

/**
 * @b Description
 * @n
 *  Function for turning servo on.
 *
 * @param[in] servo Servo pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_servoPowerOn(int8_t servo);

/**
 * @b Description
 * @n
 *  Function for turning fan off.
 *
 * @param[in] fan Fan pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_fanPowerOff(int8_t fan);

/**
 * @b Description
 * @n
 *  Function for turning heat off.
 *
 * @param[in] heat Heater pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_heatPowerOff(int8_t heat);

/**
 * @b Description
 * @n
 *  Function for turning servo off.
 *
 * @param[in] servo Servo pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_servoPowerOff(int8_t servo);

#endif