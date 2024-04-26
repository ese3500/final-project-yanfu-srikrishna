/*
 * GccApplication1.c
 *
 * Created: 4/19/2024 11:34:57 AM
 * Author : yanfuou2
 */ 

#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)
#include "inc/uart.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
volatile int pulseBegin;
volatile int pulseEnd; 
volatile int time;
volatile int distance;  
volatile int angle; 
char String[25];

volatile int writtenAngle = 0; //0 implies ready to write initial angle, 1 implies ready to write to final angle

volatile int initAngle;
volatile int finalAngle; 

volatile int initThresh = 30; 
volatile int finalThresh = 150; 

void initialize() {
	UART_init(BAUD_PRESCALER);
	UART_init_new(BAUD_PRESCALER);
	cli();
	
//	sprintf(String, "Init\n");
	//UART_putstring(String);
	
	DDRD |= (1<<DDD6); //output pin
	DDRC |= (1<<DDC0);
	DDRC |= (1<<DDC1);
	//DDRB &= ~(1<<PORTB1); //output pin
	DDRB &= ~(1<<PORTB0); //INPUT pin
	
	DDRD |= (1<<DDD5); //TC 0 --> PD5
	DDRD |= (1<<DDD3); //TC 2 --> PD3
	DDRD |= (1<<DDD2); //TC 3 --> PD2
	DDRD |= (1<<DDD0); //TC 3 --> PD0
	DDRD |= (1<<DDD1); //TC 3 --> PD1
	DDRB |= (1<<PORTB2); //TC1 --> PB2


	

	//-------------TIMER 0--------------PD5(50Hz for Motor)
	
	//prescale buzzer control Phase Correct PWM mode by 64
	TCCR0B |= (1<<CS02);
	TCCR0B &= ~(1<<CS01);
	TCCR0B |= (1<<CS00);
	
	//SETS OPERATION MODE TO BE PHASE CORRECT MODE
	TCCR0A |= (1<<WGM00);
	TCCR0A &= ~(1<<WGM01);
	TCCR0B |= (1<<WGM02);
	
	//SETS OCCR0A AND OCCR0B
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1);
	TCCR0A &= ~((1 << COM0A0) | (1 << COM0B0));
	//TIFR0 |= (1<<OCF0A); 
	OCR0A = 156;
	OCR0B = OCR0A * 90.0/100;
	
	//-------------TIMER 2 -------------------PD3(20ns for Ultrasnic sensorTrigger)
	//prescaled by 8
	//CAUTION: DIFFERENT FROM OTHER TIMERS
	TCCR2B &= ~(1<<CS22);
	TCCR2B |= (1<<CS21);
	TCCR2B &= ~(1<<CS20);
		
	//SETS OPERATION MODE TO BE PHASE CORRECT MODE
	TCCR2A |= (1<<WGM20);
	TCCR2A &= ~(1<<WGM21);
	TCCR2B |= (1<<WGM22);
	
	//SETS OCCR0A AND OCCR0B
	TCCR2A |= (1 << COM2A1) | (1 << COM2B1);
	TCCR2A &= ~((1 << COM2A0) | (1 << COM2B0));
	//TIFR0 |= (1<<OCF0A); 
	OCR2A = 20; //was 20
	OCR2B = OCR2A * 50/100;
	
	
	
	//--------------------TIMER 1---------------PB0(Ultrasonic sensor echo pin)
	//Prescale by 8
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B |= (1<<CS12);
	
	TCCR1B |= (1<<ICES1);//Input capture edge select
	TIMSK1 |= (1<<ICIE1); //Input capture interrupt enable
	TIFR1 |= (1 << ICF1); //Clear flag
	
	/*
	TCCR1A |= (1<<WGM10); 
	TCCR1A |= (1<<WGM11);
	TCCR1B &= ~(1<<WGM12); 
	TCCR1B |= (1<<WGM13); 
	
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
	TCCR1A &= ~((1 << COM1A0) | (1 << COM1B0));
	
	OCR1A = 156; //was 20
	OCR1B = OCR1A * 50/100;
	*/
	
	
/**
	//-----------------Timer 3---------------------PD2
	//prescale input captuare clock by 1024
	TCCR3B |= (1<<CS32); 
	TCCR3B &= ~(1<<CS31);
	TCCR3B |= (1<<CS30); 
	
	TCCR3A |= (1<<WGM30); 
	TCCR3A |= (1<<WGM31);
	TCCR3B &= ~(1<<WGM32); 
	TCCR3B |= (1<<WGM33); 
	
	TCCR3A |= (1 << COM3A1) | (1 << COM3B1);
	TCCR3A &= ~((1 << COM3A0) | (1 << COM3B0));
	
	OCR3A = 156; //was 20
	OCR3B = OCR3A * 50/100;
*/
	sei();
}

ISR(TIMER1_CAPT_vect) // Capture event interrupt
{
	if (TCCR1B & (1<<ICES1)) { //If rising edge detected
		pulseBegin = TCNT1; //Store counter number at beginning 
	}
	else {
		pulseEnd = TCNT1; //Store counter number at end.
		if (pulseEnd >= pulseBegin) {
			time = pulseEnd - pulseBegin; //See how many counts elapsed if no overflow occurred
		}
		else {
			time = pulseEnd - pulseBegin + 65536; //Add 2^16 = 65536 if overflow occurred since we have 16 bit timer
		}
		distance = time * 0.34/2; //Use the formula from datasheet
		//sprintf(String, "dist %d\n", distance);
		//UART_putstring(String);
		
	}
	TIFR1 |= (1<<ICF1); //clear input flag
	TCCR1B ^= (1 << ICES1);
	
}

void detection()
{
	//sprintf(String, "distance1 %d \n", distance);
	//UART_putstring(String);
	if(distance < 12 && writtenAngle == 0) {
		//stop command
		
		initAngle = angle;
		writtenAngle = 1; 
		
		//DEBUG
		//sprintf(String, "initAngle %d \n", initAngle);
		//UART_putstring(String);
	}
	if(distance >= 12 && writtenAngle == 1) {
		finalAngle = angle;
		writtenAngle = 0; 
		sprintf(String, "s\n\n");
		UART_putstring(String);
		//_delay_ms(100);
		//DEBUG
		//sprintf(String, "finalAngle %d \n", finalAngle);
		//UART_putstring(String);
	}
	if(distance < 12) {
		threshold();
	}
	
}

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}
int min(int x, int y) {
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}


void threshold() {
	int mini = min(initAngle, finalAngle);
	int maxi = max(initAngle, finalAngle);
	//sprintf(String, "mini %d \n", mini);
	//UART_putstring(String);
	
	//sprintf(String, "maxi %d \n", maxi);
	//UART_putstring(String);
	
//	sprintf(String, "initThresh %d \n", initThresh);
//	UART_putstring(String);
	
//	sprintf(String, "finalThresh %d \n", finalThresh);
//	UART_putstring(String);
	
	if((mini > initThresh) && (maxi < finalThresh)){
		sprintf(String, "l\n\n");
		UART_putstring(String);
	}
}

int main(void)
{
    /* Replace with your application code */
	initialize(); 
	/*
	for (int i = 1; i < 6; i++) {
		angle = i;
		sprintf(String, "a%03d\n", angle);
		UART_putstring_new(String);
		_delay_ms(2000);
	}
	*/
    while (1) 
    {
		
		sprintf(String, "f\n\n");
		UART_putstring(String);
		/*_delay_ms(10);
		sprintf(String, "s\n");
		UART_putstring(String);
		_delay_ms(10);*/
		
		/*
		sprintf(String, "f\n");
		UART_putstring(String);
		_delay_ms(2000);
		
		sprintf(String, "l\n");
		UART_putstring(String);
		_delay_ms(2000);
		
		sprintf(String, "b\n");
		UART_putstring(String);
		_delay_ms(2000);
		
		sprintf(String, "r\n");
		UART_putstring(String);
		_delay_ms(2000);
		
		_delay_ms(2000);
		*/
				
		for(int i = 1; i < 13; i++) {
			OCR0B = OCR0A*(100 - i)/100;
			angle = 16.36*i - 16.36;
			sprintf(String, "a%03d\n", angle);
			UART_putstring_new(String);
			detection(); 
			_delay_ms(100);
		//	sprintf(String, "OCR0B %d \n", OCR0B);
		//	UART_putstring(String);
		}
		
		for(int i = 1; i < 13; i++) {
			OCR0B = OCR0A*(88 + i)/100;
			angle = 16.36*(13-i) - 16.36;
			sprintf(String, "a%03d\n", angle);
			UART_putstring_new(String);
			detection(); 
			_delay_ms(100);
		}

	/*
	for(int i = 1; i < 10; i++) {
		sprintf(String, "a%03d\n", i);
		UART_putstring_new(String);
	    _delay_ms(50);
	}
	*/
    }
}