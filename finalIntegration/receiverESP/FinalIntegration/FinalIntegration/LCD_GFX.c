/*
 * LCD_GFX.c
 *
 * Created: 9/20/2021 6:54:25 PM
 *  Author: You
 */ 

#include "stdio.h"
#include "LCD_GFX.h"
#include "ST7735.h"
#include "math.h"

// #define F_CPU 16000000UL
// #define BAUD_RATE 9600
// #define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)
// #include "uart.h"

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <math.h>
/*char String[25];*/

/******************************************************************************
* Local Functions
******************************************************************************/



/******************************************************************************
* Global Functions
******************************************************************************/

/**************************************************************************//**
* @fn			uint16_t rgb565(uint8_t red, uint8_t green, uint8_t blue)
* @brief		Convert RGB888 value to RGB565 16-bit color data
* @note
*****************************************************************************/
uint16_t rgb565(uint8_t red, uint8_t green, uint8_t blue)
{
	return ((((31*(red+4))/255)<<11) | (((63*(green+2))/255)<<5) | ((31*(blue+4))/255));
}

/**************************************************************************//**
* @fn			void LCD_drawPixel(uint8_t x, uint8_t y, uint16_t color)
* @brief		Draw a single pixel of 16-bit rgb565 color to the x & y coordinate
* @note
*****************************************************************************/
void LCD_drawPixel(uint8_t x, uint8_t y, uint16_t color) {
	LCD_setAddr(x,y,x,y);
	SPI_ControllerTx_16bit(color);
}

/**************************************************************************//**
* @fn			void LCD_drawChar(uint8_t x, uint8_t y, uint16_t character, uint16_t fColor, uint16_t bColor)
* @brief		Draw a character starting at the point with foreground and background colors
* @note
*****************************************************************************/
void LCD_drawChar(uint8_t x, uint8_t y, uint16_t character, uint16_t fColor, uint16_t bColor){
	uint16_t row = character - 0x20;		//Determine row of ASCII table starting at space
	int i, j;
	if ((LCD_WIDTH-x>7)&&(LCD_HEIGHT-y>7)){
		for(i=0;i<5;i++){
			uint8_t pixels = ASCII[row][i]; //Go through the list of pixels
			for(j=0;j<8;j++){
				if ((pixels>>j)&1==1){
					LCD_drawPixel(x+i,y+j,fColor);
				}
				else {
					LCD_drawPixel(x+i,y+j,bColor);
				}
			}
		}
	}
}


/******************************************************************************
* LAB 4 TO DO. COMPLETE THE FUNCTIONS BELOW.
* You are free to create and add any additional files, libraries, and/or
*  helper function. All code must be authentically yours.
******************************************************************************/

/**************************************************************************//**
* @fn			void LCD_drawCircle(uint8_t x0, uint8_t y0, uint8_t radius,uint16_t color)
* @brief		Draw a colored circle of set radius at coordinates
* @note
*****************************************************************************/
void LCD_drawCircle(uint8_t x0, uint8_t y0, uint8_t radius,uint16_t color)
{
	/*
	for(int i = x0; i < x0 + radius; i++) {
		for(int j = y0; j < y0 + radius; j++ ) {
			int d = sqrt((i- x0)*(i-x0) + (j-y0)(j-y0)); 
			if(d < radius) {
				LCD_drawPixel(i,j,color); 
			}
		}
	}
	*/
	
	LCD_setAddr(x0-radius, y0 - radius, x0 + radius, y0 + radius); 
	int r2 = radius * radius; 
	for(int i = x0-radius; i <= x0 + radius; i++) {
		for(int j = y0 - radius; j <= y0 + radius; j++) {
			int dist = (i - x0)*(i - x0) + (j - y0)*(j - y0); 
			if(dist <= r2) {
				SPI_ControllerTx_16bit(color);
			}	
			else {
				SPI_ControllerTx_16bit(WHITE);
			}
		}
	}

}


/**************************************************************************//**
* @fn			void LCD_drawLine(short x0,short y0,short x1,short y1,uint16_t c)
* @brief		Draw a line from and to a point with a color
* @note
*****************************************************************************/
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
void LCD_drawLine(short x0,short y0,short x1,short y1,uint16_t c)
{

		uint8_t minX = min(x0, x1);
		uint8_t maxX = max(x0, x1);
		short deltaX = x1 - x0;
		uint8_t absDeltaX = maxX - minX;

		uint8_t minY = min(y0, y1);
		uint8_t maxY = max(y0, y1);
		short deltaY = y1 - y0;
		uint8_t absDeltaY = maxY - minY;

		if (deltaX == 0 || deltaY == 0) {
			LCD_drawBlock(x0, y0, x1, y1, c);
			return;
		}

		if (absDeltaX >= absDeltaY) {
			// |slope| <= 1
			for (uint8_t x = minX; x <= maxX; x++) {
				uint8_t y = (deltaY * (x - minX)) / (absDeltaX) + y0;
				LCD_drawPixel(x, y, c);
			}
		} 
		
		
		else {
			// |slope| > 1
			/*
			for (uint8_t y = minY; y <= maxY; y++) {
				uint8_t x = (deltaX * (y - minY)) / (absDeltaY) + x0;
				LCD_drawPixel(x, y, c);
			}
			*/
			 for (uint8_t x = minX; x <= maxX; x++) {
				uint8_t y = (deltaY * (x - minX)) / absDeltaX + y0;
				  LCD_drawPixel(x, y, c);
		     }
		}
		
	
}



/**************************************************************************//**
* @fn			void LCD_drawBlock(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,uint16_t color)
* @brief		Draw a colored block at coordinates
* @note
*****************************************************************************/
void LCD_drawBlock(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color)
{

	LCD_setAddr(x0,y0,x1,y1); 
	for(int i = 0; i < (x1-x0) * (y1-y0); i++) {
		SPI_ControllerTx_16bit(color);
	}
	// Fill this out
}

void LCD_moveBlockY(uint8_t *x0, uint8_t *y0, uint8_t *x1, uint8_t *y1, int8_t deltaY, uint16_t color)
{
	if(*y1 + deltaY <= LCD_HEIGHT && *y0 + deltaY >= 0) {
		if(deltaY > 0) {
			LCD_drawBlock(*x0,*y0,*x1,*y0+deltaY,WHITE); 
			LCD_drawBlock(*x0,*y1,*x1,*y1+deltaY,color); 
		
		}
		else {
			LCD_drawBlock(*x0,*y1 + deltaY,*x1,*y1,WHITE);
			LCD_drawBlock(*x0,*y0 + deltaY,*x1,*y0,color);
		
		}
		*y0 += deltaY;
		*y1 += deltaY;
	}
	else {
		UART_putstring("Out of bounds"); 
	}

	 
	 

}
void LCD_moveBall(int *x0, int *y0, int *vx, int *vy, int radius, int color) {
	//clear the old mark
	LCD_drawCircle(*x0, *y0, radius, WHITE); 
		*x0 += *vx;
		*y0 += *vy; 
		LCD_drawCircle(*x0, *y0, radius, GREEN); 

}


/**************************************************************************//**
* @fn			void LCD_setScreen(uint16_t color)
* @brief		Draw the entire screen to a color
* @note
*****************************************************************************/
void LCD_setScreen(uint16_t color) 
{
	
 	LCD_setAddr(0,0,LCD_WIDTH-1,LCD_HEIGHT-1);
	 
 	for(int i = 0; i < LCD_WIDTH * LCD_HEIGHT; i++) {
		SPI_ControllerTx_16bit(color);
	}


	
}

/**************************************************************************//**
* @fn			void LCD_drawString(uint8_t x, uint8_t y, char* str, uint16_t fg, uint16_t bg)
* @brief		Draw a string starting at the point with foreground and background colors
* @note
*****************************************************************************/
void LCD_drawString(uint8_t x, uint8_t y, char* str, uint16_t fg, uint16_t bg)
{
	// Fill this out
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		LCD_drawChar(x + i*5,y,str[i], fg, bg); 
	}
}