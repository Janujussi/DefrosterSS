
/** FILE: DefrosterSS_Transceiver.h
 *
 * @brief Contains all transceiver functions of the defroster sub-system.
*/

#ifndef DEFROSTERSS_TRANSCEIVER_H
#define DEFROSTERSS_TRANSCEIVER_H

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* DefrosterSS Include Files */
#include "DefrosterSS.h"

/* Transceiver Include Files */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

/**
 * @b Decription
 * @n
 *  Setup nRF24L01.
 *
 * @param[in] radio Transceiver unit.
 */
void DefrosterSS_Transceiver_Init(RF24& radio);

/**
 * @b Description
 * @n
 * 	Parse available radio message.
 *
 * @param[in] radio Transceiver unit.
 *
 * @retval
 * 	Pointer to message buffer.
 */
byte* DefrosterSS_getMsg(RF24 radio);

/**
 * @b Description
 * @n
 * 	Send message to keychain fob.
 *
 * @param[in] handle DefrosterSS handle.
 * @param[in] radio Transceiver unit.
 *
 * @retval
 * 	Non applicable.
 */
void DefrosterSS_sendMsg(DefrosterSS handle, RF24 radio);

#endif