/** FILE: DefrosterSS_Power.h
 *
 * @brief Contains all power functions of the defroster sub-system.
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
 *  Function for turning fan on.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_fanPowerOn();

/**
 * @b Description
 * @n
 *  Function for turning heat on.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_heatPowerOn();

/**
 * @b Description
 * @n
 *  Function for turning servo on.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_servoPowerOn();

/**
 * @b Description
 * @n
 *  Function for turning fan off.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_fanPowerOff();

/**
 * @b Description
 * @n
 *  Function for turning heat off.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_heatPowerOff();

/**
 * @b Description
 * @n
 *  Function for turning servo off.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_servoPowerOff();