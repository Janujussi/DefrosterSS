/** FILE: DefrosterSS_System.h
 *
 * @brief Contains all system functions of the defroster sub-system.
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
 *  Initializes defroster sub-system on power up.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_System_Init();

/**
 * @b Description
 * @n
 *  Configures defroster sub-system.
 *
 * @retval
 * 	SUCCESS or FAIL.
 */
uint8_t DefrosterSS_System_Configuration(DefrosterSS handle);

/**
 * @b Description
 * @n
 *  Assigns system parameters on power up.
 *
 * @retval
 * 	Non applicable.
 */
void DefrosterSS_Init_Parameters(DefrosterSS handle);