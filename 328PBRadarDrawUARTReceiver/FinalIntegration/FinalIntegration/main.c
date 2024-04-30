#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)
#include "inc/uart.h"

#include <avr/io.h>
#include "ST7735.h"
#include "LCD_GFX.h"
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <math.h>
char String[25];
volatile int x = 0, y = 0;
volatile int xcenter = 0, ycenter = LCD_HEIGHT/2;
volatile int r = LCD_HEIGHT/2; 
volatile int oldx;
volatile int oldy;
volatile int angle; 
char angleArr[5]; 
int isDisplay = 0; 

char intStringBuffer[10]; //buffer to hold the converted number
void Initialize()
{
	cli();
	UART_init(BAUD_PRESCALER);
	//Initialize output pins
	lcd_init();//initialize LCD
	//clear the screen
	LCD_setScreen(BLACK);
	sei();
	

}

void sweep() {  

	oldx = x;
	oldy = y; 
	x = xcenter + r*cos((90-angle)* 3.1415926535 /180); 
	y = ycenter + r*sin((90-angle)*  3.1415926535 /180); 
	LCD_drawLine(xcenter,ycenter,oldx,oldy,BLACK);
	LCD_drawLine(xcenter,ycenter,x,y,GREEN);
	_delay_ms(25); 
}

int main(void)
{
	Initialize();
	
	 while (1)
	 {
		 char received = UART_receive();
		 UART_send(received);
		 if(received == 'a') {
			 for(int i = 0; i < 3; i++) {
				 angleArr[i] = UART_receive();
			 }
			 
			 //if(isDisplay %2 == 0) {
				 		
				 angle = atoi(angleArr); 
				 sprintf(String, "angle: %03d\n", angle);
				 UART_putstring(String);
		
				//_delay_ms(800);
				LCD_drawBlock(100, 100, 150, 120, BLACK); 
				 LCD_drawString(10,10,angleArr,WHITE,BLACK);
				 
				 UART_putstring(angleArr); 
				 //_delay_ms(150);
				 isDisplay++; 
				 sweep();
				 
			 //}
		
		 }
		 else {
			  LCD_drawString(100,100,"waiting",WHITE,BLACK);
		 }

	 }
}