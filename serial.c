#include <avr/io.h>
#include <string.h> 
#include <util/delay.h>
#define FOSC 16000000UL
#define BAUD 38400
#define MYUBRR (FOSC/(16UL*BAUD)-1)

#include "serial.h"

// Buffer to store thr typed characters
char INPUT_BUFF[255];   
int Buff_Index =0;

//variable to hold the entered char
char InputChar;



//UART funtion to initiate the tramiter and receiver funtionalities
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


//function to put a character on screen.
void uart_putchar(char chr)
{
    ////ATmega 328p Datasheet page 186 Ca 20.6
    // Wait for empty transmit buffer, UDRE0 is 1 when buffer is set 1(stating an empty buffer)
     while (!(UCSR0A & (1<<UDRE0)))
    ;
     /* Put data into buffer(USART Data Register), sends the data */
      UDR0 = chr; 

      // If carriage return and newline to it.
     if(chr =='\r')
       { 
          uart_putchar('\n');
         
        }     
    
}

//function to put a string on the screen

void uart_putstr(const char *str){
   
    // loop through entire string

     for(int i = 0; str[i] !='\0'; i++){
        uart_putchar(str[i]);
     } 

     //This loop also works
  /*  while (*str != '\0')
   {
       const char ch = *str;
        uart_putchar(ch);
        str++;
    }*/
}


// Funtion to get charaters typed 
char uart_getchar(void){
 // received character in a first-in-first out (FIFO) buffer   
//Wait for data to be received 
while ( !(UCSR0A & (1<<RXC0)) )
;
 
 //If the input char is a newline(In linux , when enter is pressed it is read as c)
 //https://askubuntu.com/questions/441744/pressing-enter-produces-m-instead-of-a-newline
 //$ stty -a  ----> and then
 //$ stty -icrnl   "turn carriage returns into newlines”
//if(UDR0 == 13){

//return UDR0 = '\n';
//}
    //Get and return received data from buffer
    return UDR0;
}

//Get the charecters typed on keyboard and store in a buffer
void read_line(void){
    
    InputChar = uart_getchar();
    if(InputChar == 13)                 //if char is \r (ascii value 13) ( newline) add it to the buffer anlog with \n .
    {   
        INPUT_BUFF[Buff_Index] = InputChar;

        Buff_Index++;

        INPUT_BUFF[Buff_Index] ='\n';
        INPUT_BUFF[++Buff_Index] ='\0';   //adding the string terminater

        Buff_Index = 0;                   //  Reassigning the index
        return;
    }
    else if (InputChar >= 47){                   //so that charaters only above ascii value 47 to be stored. 
        INPUT_BUFF[Buff_Index] = InputChar;
        Buff_Index++;

    }
}

//To display the typed characters on the screen

void uart_echo(void){

   
    read_line();       //getting the line of characters
   
    uart_putchar(InputChar); // putting the read charecters on the screen
    
}


//Function to  controll the LED
//comparing with the string if typed on/ON and pressed enter, results in string on\r\n accoring to the program written.
int Led_on_off(){
    	
    if((strcmp(INPUT_BUFF,"on\r\n") == 0) || (strcmp(INPUT_BUFF,"ON\r\n") == 0))
			{
                return 1;
				
			}
			else if((strcmp(INPUT_BUFF,"off\r\n") == 0) || (strcmp(INPUT_BUFF,"OFF\r\n") == 0))
			{
                return 0;
				
			}
}
