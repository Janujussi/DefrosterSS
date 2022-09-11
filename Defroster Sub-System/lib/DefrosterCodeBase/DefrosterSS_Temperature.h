/** FILE: DefrosterSS_Temperature.h
 *
 * @brief Contains all temperature functions of the defroster sub-system.
*/

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
 * 	Check temperature.
 *
 * @param[in] handle DefrosterSS handle.
 *
 * @retval
 * 	Temperature.
 */
uint8_t DefrosterSS_checkTemp(void* handle);

/**
 * @b Description
 * @n
 * 	Turn heat on.
 *
 * @param[in] handle DefrosterSS handle.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_cutHeatOn();

/**
 * @b Description
 * @n
 * 	Turn heat off.
 *
 * @param[in] handle DefrosterSS handle.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_cutHeatOff();