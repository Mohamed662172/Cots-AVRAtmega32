/*
 * kpadTest.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#include"Bit_Math.h"
#include"Std_Types.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include"DIO_interface.h"

#include"LCD_interface.h"
#include"KPAD_interface.h"



int main(void ){

_uint8 Local__Uint8Var;

DIO__CheckStatusInit();
LCD_VoidInit4bit();

while(TRUE)
{

KPAD_CheckStatusGetKey(&Local__Uint8Var);

 if(Local__Uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
 {

	 LCD_CheckStatusSendChar4bit(Local__Uint8Var);
     if(Local__Uint8Var == 'D')
     {
	           LCD_VoidClearDisplay();
     }
 }
}
/*
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_HIGH);
    _delay_ms(5000);
    DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_LOW);
    _delay_ms(5000);
if(DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_LOW)== CHECK_SUCCESS)
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_HIGH);
	_delay_ms(500);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_LOW);
	_delay_ms(500);
}
_delay_ms(5000);
}
*/
	return 0;
}
