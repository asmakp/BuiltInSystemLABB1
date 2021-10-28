#ifndef SERIAL_H_
#define SERIAL_H_

void uart_init(void);

void uart_putchar(char chr);
void uart_putstr(const char *str);

char uart_getchar(void);

//void uart_echo(void);
//void uart_echo(char *str);
void readchar(void);
//void readchar(char *str);
int Led_on_off(void);
//void blink(void);
//void uart_output(char *str);

//void readchar(void);

#endif

