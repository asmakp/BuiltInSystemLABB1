#include <avr/io.h>
#include <util/delay.h>
#define FOSC 16000000UL
#define BAUD 38400
#define MYUBRR (FOSC/(16UL*BAUD)-1)

#include "serial.h"

void uart_init(void){
    //ATmega 328p Datasheet page 185 Ca 20.5
    // Enable Transmitter
    // UCSR0B |= _BV(TXEN0);
    // Enable receiver
    // UCSR0B |= _BV(RXEN0);
    // Enable both transmiter and receiver
       UCSR0B = (1<<RXEN0)|(1<<TXEN0);

   // Assigning Baud rate to register 
      //uint16_t MYUBRR  = FOSC/(16*BAUD)-1;
      UBRR0H = (unsigned char)(MYUBRR>>8);
      UBRR0L = (unsigned char) MYUBRR;

     //UBRR0 = MYUBRR;

    //  Setting frame formate .8N1- 8 bit data and 1 parity
    //Frame formate controlled by USART control status register C 
    UCSR0C |= (1<< UCSZ01) | (1<< UCSZ00);
    UCSR0C &= ~_BV(USBS0);  // setting parity bit with 0 means 1 bit parity

}
void uart_putchar(char chr)
{
    ////ATmega 328p Datasheet page 186 Ca 20.6
    // Wait for empty transmit buffer, UDRE0 is 1 when buffer is set 1
     while (!(UCSR0A & (1<<UDRE0)))
    ;
     /* Put data into buffer(USART Data Register), sends the data */
      UDR0 = chr;
      if(chr == '\n')
       { 
          uart_putchar('\r');

        }
     
    
}
void uart_putstr(const char *str){
   
    // loop through entire string

     //const char str[] = s;
      int i;

     for(i = 0; str[i] !='\0'; i++){
        uart_putchar(str[i]);
     } 

     
  /*  while (*str != '\0')
   {
       const char ch = *str;
        uart_putchar(ch);
        str++;
    }*/
}