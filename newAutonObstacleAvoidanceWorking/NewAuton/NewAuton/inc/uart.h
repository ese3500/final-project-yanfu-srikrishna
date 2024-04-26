#ifndef UART_H
#define UART_H

void UART_init(int prescale);

void UART_send( unsigned char data);

void UART_putstring(char* StringPtr);

void UART_init_new(int prescale);

void UART_send_new( unsigned char data);

void UART_putstring_new(char* StringPtr);

#endif 