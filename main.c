#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 1

#include "serial.h"

void main (void) {

		DDRB |= (1 << LED_PIN); // set pin as input
		while (1)
		{
			PORTB ^= (1 << LED_PIN);
			_delay_ms(500);
		}


}