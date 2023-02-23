/*
 * calc.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
/* Liberary Layer */
#include"Bit_Math.h"
#include"Std_Types.h"
#define F_CPU  8000000UL
#include<util/delay.h>

/*mcal layer */
#include"DIO_interface.h"

/*Hal Layer  */
#include "LCD_interface.h"
#include"KPAD_interface.h"


int main(void)
{
//_uint8 Local__uint8Var;
/* Dio init */
DIO_VoidInit();


/*LCD init*/
LCD_VoidInit4bit();
//LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER4);
LCD_CheckStatusWriteString("Welcome Hyiam Mahfouz");

while(TRUE)
{

	LCD_CheckStatusShiftRightOrLeft(350);
/*

     KPAD_CheckStatusGetKey(&Local__uint8Var);

	 if(Local__uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
	 {

		 LCD_CheckStatusSendChar(Local__uint8Var);
	     if(Local__uint8Var == 'D')
	     {
		           LCD_VoidClearDisplay();
	     }
	 }
*/
}
	return 0;
}
