/** FILE: DefrosterSS_Checks.h
 *
 * @brief Contains all check functions of the defroster sub-system.
*/

#ifndef DEFROSTERSS_CHECKS_H
#define DEFROSTERSS_CHECKS_H

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* DefrosterSS Include Files. */
#include "DefrosterSS.h"

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

/**
 * @b Description
 * @n
 * 	Checks whether Defroster is too hot.
 *
 * @param[in] handle DefrosterSS handle.
 *
 * @retval
 * 	Temperature.
 */
uint16_t DefrosterSS_checkTemp(DefrosterSS handle);

#endif