/*
 * LCD_program.c
 *
 *  Created on: Apr 30, 2022
 *      Author: mazen
 */


#include "../STD_TYPES.h"

#include "../DIO/DIO_interface.h"
#include <util/delay.h>

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



void LCD_SendCommand(u8 command)
{
	/* 1- Set RS pin -> for command=LOW */
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW);
	/* 2- set RW pin -> for write=LOW   */
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);
	/* 3- set DB pins -> write your command */
	DIO_SetPortValue(LCD_DATA_PORT, command);
	/* 4- send an Enable pulse */
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW );
	_delay_ms(1);
}

void LCD_SendChar(char c)
{
	/* 1- Set RS pin -> for char=HIGH */
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH);
	/* 2- set RW pin -> for write=LOW   */
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);
	/* 3- set DB pins -> write your command */
	DIO_SetPortValue(LCD_DATA_PORT, c);
	/* 4- send an Enable pulse */
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW );
	_delay_ms(1);
}


void LCD_Init(void)
{
	/* 1-set LCD CTRL port and LCD DATA port to output */
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, DIO_OUTPUT);
	DIO_SetPortDirection(LCD_DATA_PORT, 0xff);

	_delay_ms(50);
	/* 2- Function set command: N=1, F=0 */
	LCD_SendCommand(0b00111000);
	_delay_ms(1);
	/* 3- Display ON/OFF command: D=1, C=B=0 */
	LCD_SendCommand(0b00001100);
	_delay_ms(1);
	/* 4- Display Clear command:  */
	LCD_SendCommand(0b00000001);
	_delay_ms(3);
	/* 5- Entry mode command:  I/D=1 , SH=0 */
	LCD_SendCommand(0b00000110);
	_delay_ms(5);
}

void LCD_PrintString(char str[])
{
	for(u32 i=0; str[i] != '\0'; i++)
	{
		LCD_SendChar(str[i]);
	}
}

void LCD_PrintNumber(s32 num)
{
	u8 digits[11] = {0} ;

	/* extract each digit in the array (reversed) */
	u8 i=0;
	while(num > 0)
	{
		digits[i] = num%10 ; // extract units digit
		num /= 10 ; // shift the number to the right by one decimal place
		i++ ;
	}

	for(s8 j=i-1; j>=0; j--)
	{
		LCD_SendChar(digits[j] + '0'); // convert digit to ASCII representation
	}
}

void LCD_ClearDisplay(void)
{
	LCD_SendCommand(LCD_CLEAR);
}


void LCD_DisplayCustomChar(u8 address)
{
	if(address < 8)
	{
		LCD_SendChar(address);
	}
}

void LCD_SaveCustomChar(u8 address, u8 array[])
{
	if(address < 8)
	{
		LCD_SendCommand(0b01000000 + (address*8)); // 0b01000000 -> 0x???

		for(u8 i=0; i<8; i++)
		{
			LCD_SendChar(array[i]);
		}
		LCD_SendCommand(0b10000000  ); // 0b10000000 --> 0x??
	}
}


void LCD_SetCursorPosition(u8 linePos, u8 lineNo)
{
	switch(lineNo)
	{
		case 0:
			LCD_SendCommand(0b10000000 + linePos);
			break;
		case 1:
			LCD_SendCommand(0b10000000 + linePos + 64);
			break;
	}
}













