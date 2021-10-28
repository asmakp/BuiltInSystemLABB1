#include <avr/io.h>
#include <util/delay.h>
//#define FOSC 16000000UL
//#define BAUD 9600
//#define MYUBRR (FOSC/(16*BAUD)-1)

#define LED_PIN 3

#include "serial.h"

void main (void) {

		DDRB |= (1 << LED_PIN); // set pin as input
        uart_init();
		//char DATA[255];
        
		//const char arr[] = "Asma";
		//uart_putstr("ASMA\n");
		
		while (1)
		{
			//PORTB ^= (1 << LED_PIN);
			//uart_putstr("ASMA\n");
			
		    // uart_putchar('O');
			// uart_putchar('N');
			// uart_putchar('\n');
			 uart_echo();
			//uart_echo();

			int result = Led_on_off();

			if(result == 1){
				
				PORTB &= ~(1<<LED_PIN);
			}
			
			else if(result == 0) {
				PORTB |= (1<<LED_PIN);
			}

			
			
			//_delay_ms(200);
		}
}
