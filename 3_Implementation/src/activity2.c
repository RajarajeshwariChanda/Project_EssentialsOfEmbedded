#include "Activity2.h"

void LCD_CMD( unsigned char command )
{
	PORT_B = (PORT_B & 0x0F) | (command & 0xF0); 
	PORT_B &= ~ (1<<LCD_RS); 
	PORT_B |= (1<<LCD_EN); 
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);

	_delay_us(250);

	PORT_B = (PORT_B & 0x0F) | (command << 4); 
	PORT_B |= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);
	_delay_ms(50);
}

void LCD_CHAR_WISE( unsigned char ch )
{
	PORT_B = (PORT_B & 0x0F) | (ch & 0xF0); 
	PORT_B |= (1<<LCD_RS);		
	PORT_B|= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);

	_delay_us(250);

	PORT_B = (PORT_B & 0x0F) | (ch << 4); 
	PORT_B |= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);
	_delay_ms(50);
}

void LCD_INITIALIZATION(void)
{
	LCD_DIRECTION = 0xFF; 
	_delay_ms(50);

	LCD_CMD(0x02);	
	LCD_CMD(0x28);  
	LCD_CMD(0x0c);  
	LCD_CMD(0x06);  
	LCD_CMD(0x01); 
	_delay_ms(5);
}

void LCD_DISPLAY (char *temperature_value)
{
	int Index;
	for(Index=0;temperature_value[Index]!=0;Index++)
	{
		LCD_CHAR_WISE(temperature_value[Index]);
	}
}


void CLEAR_LCD()
{
	LCD_CMD (0x01);
	_delay_ms(50);
	LCD_CMD (0x80);	
}
