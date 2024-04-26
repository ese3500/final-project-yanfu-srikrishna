/*
 * GccApplication1.c
 *
 * Created: 3/9/2024 3:21:26 PM
 * Author : yanfuou2
 */ 
#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)
#include "inc/uart.h"

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
char String[25];



void Initialize() {
	UART_init_new(BAUD_PRESCALER);
	sprintf(String, "test\n");
	UART_putstring_new(String);
	cli();
	sei(); 
}
int main(void)
{
	Initialize(); 
    /* Replace with your application code */
    while (1) 
    {
		sprintf(String, "f\n");
		UART_putstring_new(String);
		_delay_ms(500);
		
		sprintf(String, "s\n");
		UART_putstring_new(String);
		_delay_ms(500);
		
		sprintf(String, "b\n");
		UART_putstring_new(String);
		_delay_ms(500);
		
		sprintf(String, "r\n");
		UART_putstring_new(String);
		_delay_ms(500);

		
    }
}