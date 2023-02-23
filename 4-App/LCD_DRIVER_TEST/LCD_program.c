/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	23/8/2020	****************************************************/
/*********	SWC		:	LCD			****************************************************/
/*********	Version	:	V1.0		****************************************************/
/***************************************************************************************/

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util\delay.h>

#include "DIO_interface.h"


#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
	_delay_ms(35);					// Wait More Than 30ms After VDD rises to 4.5 V
	LCD_u8SendCmnd(0b00111000);
	_delay_us(40);
	LCD_u8SendCmnd(0b00001111);
	_delay_us(40);
	LCD_u8SendCmnd(0b00000001);
	_delay_ms(2);
	LCD_u8SendCmnd(0b00000110);
}

u8 LCD_u8SendCmnd(u8 Copy_u8Cmnd) 
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_u8Cmnd <= 255 )
	{	
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_LOW );	// Instruction Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPortValue( LCD_DATA_PORT , Copy_u8Cmnd ) ;					// Send The Command To LCD Pins

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}	

	return Local_u8ErrorStatus ;
}


u8 LCD_u8SendData(u8 Copy_u8Data)
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_u8Data <= 255 )
	{	
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_HIGH );	// Data Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPortValue( LCD_DATA_PORT , Copy_u8Data ) ;					// Send The Data To LCD Pins

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}	

	return Local_u8ErrorStatus ;
}
