/** FILE: DefrosterSS_System.h
 *
 * @brief Contains all system functions of the defroster sub-system.
*/

#ifndef DEFROSTERSS_SYSTEM_H
#define DEFROSTERSS_SYSTEM_H

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
 *  Initializes defroster sub-system hardware on power up.
 *
 * @param[in] handle Configuration handle.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_System_Init_HW(
	DefrosterSS_HWObj* HWObj,
	const uint8_t fan,
	const uint8_t heater,
	const uint8_t thermostat
);

/**
 * @b Description
 * @n
 *  Initializes defroster sub-system parameters.
 *
 * @param[in] handle Configuration handle.
 * @param[in] fan System's fan pin.
 * @param[in] heater System's heater pin.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_System_Init_Params(DefrosterSS_CFGObj CFGObj, DefrosterSS_HWObj HWObj);

/**
 * @b Description
 * @n
 *  Configures defroster sub-system.
 *
 * @param[in] handle Configuration handle.
 * @param[in] buffer Buffer of parameters from RF transceiver.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
void DefrosterSS_System_Configure(DefrosterSS* handle, byte* buffer);

/**
 * @b Description
 * @n
 *  Assigns system parameters on power up.
 *
 * @param[in] handle Configuration handle.
 *
 * @retval
 * 	Non applicable.
 */
void DefrosterSS_PowerUp_Parameters(DefrosterSS_CFGObj* handle);

#endif