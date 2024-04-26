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
volatile int r = LCD_HEIGHT/4; 
volatile int oldx;
volatile int oldy;
volatile int angle = 0; 

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
	
	//LCD_drawLine(xcenter,ycenter,20,10,RED);
	//LCD_drawLine(xcenter,ycenter,80,40,WHITE);
	//LCD_drawLine(xcenter,ycenter,90,70,WHITE);
	//LCD_drawLine(xcenter,ycenter,20,120,WHITE);

}
void sweep() {  
	for(int i = 0; i < 180; i++) {
		itoa(i, intStringBuffer, 10); 		
		LCD_drawString(10,10,intStringBuffer,WHITE,BLACK);
		oldx = x;
		oldy = y; 
		x = xcenter + r*cos((i-90)* 3.1415926535 /180); 
		y = ycenter + r*sin((i-90)*  3.1415926535 /180); 
		LCD_drawLine(xcenter,ycenter,oldx,oldy,BLACK);
		LCD_drawLine(xcenter,ycenter,x,y,GREEN);
		_delay_ms(50); 
	}
	for(int i = 180; i > 0; i--) {
		itoa(i, intStringBuffer, 10); 		
		LCD_drawString(10,10,intStringBuffer,WHITE,BLACK);
		oldx = x;
		oldy = y; 
		x = xcenter + r*cos((i-90)* 3.1415926535 /180); 
		y = ycenter + r*sin((i-90)*  3.1415926535 /180); 
		LCD_drawLine(xcenter,ycenter,oldx,oldy,BLACK);
		LCD_drawLine(xcenter,ycenter,x,y,GREEN);
		_delay_ms(50); 
	}
	/**
    while(y>=0) {
		LCD_drawLine(xcenter,ycenter,oldx,oldy,BLACK);
		LCD_drawLine(xcenter,ycenter,x,y,GREEN);
		oldx = x;
		oldy = y;
        y--;
		sprintf(String, "test\n");
		UART_putstring(String);

    }*/
/**    
    y = 0; x = 1;
    while(x<=127) {
		LCD_drawLine(xcenter,ycenter,oldx,oldy,BLACK);
        LCD_drawLine(xcenter,ycenter,x,y,GREEN);
		oldx = x;
		oldy = y;
        x++;

    }
    x = 127; y = 1;
    while(y<63) {
	   LCD_drawLine(xcenter,ycenter,oldx,oldy,BLACK);
       LCD_drawLine(xcenter,ycenter,x,y,GREEN);
	   oldx = x;
	   oldy = y;
       y++;

    }
	*/
}

int main(void)
{
	Initialize();
	sweep();
}