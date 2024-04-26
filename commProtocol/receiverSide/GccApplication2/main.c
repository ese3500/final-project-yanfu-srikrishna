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
char angle[5]; 


void Initialize() {
	UART_init(BAUD_PRESCALER);
	
	sprintf(String, "init\n");
	UART_putstring(String);
	
	DDRB |= (1<<DDRB0);
	 
	cli();
	sei(); 
}
int main(void)
{
	Initialize(); 
    /* Replace with your application code */
    while (1) 
    {
		char received = UART_receive(); 
		//UART_send(received);
		if(received == 'a') {
			for(int i = 0; i < 3; i++) {
				angle[i] = UART_receive(); 
			}
			UART_putstring(angle); 
			UART_putstring("\n"); 
		}
			
    }
	
}
