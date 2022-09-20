
/** FILE: DefrosterSS_Timer.c
 *
 * @brief Implementation of DefrosterSS_Timer.h.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

#include "DefrosterSS_Timer.h"

/**************************************************************************
 *************************** Functions Implementations ********************
 **************************************************************************/

void DefrosterSS_Timer_SystemTimerConfiguration() {
	cli();	// Interrups disabled for configuration

	/* A channel not needed */
	TCCR1A = 0;	// Disabled PWM signal on pins 9 and 10

	/* Configuring B channel */
	TCCR1B = 0;
	TCCR1B |= 0b00000100;	// Prescaler set to 256
	TIMSK1 |= 0b00000010;	// Compare match A enabled
	TCNT1 = 0;	// Value reset
	OCR1A = 62500;	// Set compare match value

	sei();	// Enabled interrupts
}