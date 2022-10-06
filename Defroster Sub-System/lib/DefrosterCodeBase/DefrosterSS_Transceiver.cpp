
/** FILE: DefrosterSS_Transceiver.h
 *
 * @brief Contains all transceiver functions of the defroster sub-system.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

#include "DefrosterSS_Transceiver.h"

/* Transceiver Include Files */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


/**************************************************************************
 *************************** Definitions **********************************
 **************************************************************************/

const byte address[6] = "00001";

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

void DefrosterSS_Transceiver_Init(RF24 radio) {
	radio.begin();

	// Set listening address
	radio.openReadingPipe(0, address);

	// Set module as receiver
	radio.startListening();
}

byte* DefrosterSS_getMsg(RF24 radio) {
	static byte* buffer = (byte*) calloc(5, sizeof(byte));
	radio.read(&buffer, sizeof(buffer));

	return buffer;
}

void DefrosterSS_sendMsg(DefrosterSS handle, RF24 radio) {

}