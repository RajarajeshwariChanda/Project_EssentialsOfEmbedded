#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED

#include <avr/io.h>			
#include <util/delay.h>			

#define LCD_DIRECTION  DDRB			
#define PORT_B PORTB			
#define LCD_RS PB2				
#define LCD_EN PB3 				

void LCD_CMD( unsigned char command );
void LCD_CHAR_WISE( unsigned char ch );
void LCD_INITIALIZATION(void);
void LCD_DISPLAY (char *temperature_value);
void CLEAR_LCD();

#endif 
