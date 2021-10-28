#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 3

#include "serial.h"

void main (void)
 {

	DDRB |= (1 << LED_PIN); // set pin as input, portB pin pin 11
    uart_init();
		
    while (1)
	{
		//PORTB ^= (1 << LED_PIN);
		//_delay_ms(200);

		// uart_putchar('O');
		// uart_putchar('N');
		// uart_putchar('\n');

		//uart_putstr("ASMA\n");
        

		uart_echo();
			
        //controlling the led via screen by calling function Led_on_off()
		int result = Led_on_off();

			if(result == 1){
				
				PORTB &= ~(1<<LED_PIN);
			}
			
			else if(result == 0) {
				PORTB |= (1<<LED_PIN);
			}

	}
}
