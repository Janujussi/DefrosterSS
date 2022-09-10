/** FILE: DefrosterSS_Checks.h
 *
 * @brief Contains all check functions of the defroster sub-system.
*/

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
 * 	Checks what state the defroster should be in.
 *
 * @param[in] handle DefrosterSS handle.
 *
 * @retval
 * 	ON or OFF.
 */
uint8_t DefrosterSS_checkState(DefrosterSS handle);

/**
 * @b Description
 * @n
 * 	Checks what mode the defroster should be in.
 *
 * @param[in] handle DefrosterSS handle.
 *
 * @retval
 * 	Mode enum.
 */
uint8_t DefrosterSS_checkMode(DefrosterSS handle);
