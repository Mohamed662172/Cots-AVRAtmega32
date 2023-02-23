/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include"Std_Types.h"
#include"Bit_Math.h"
#define F_CPU  8000000UL
#include"util/delay.h"
#include "DIO_interface.h"
#include "UART_interface.h"



int main()
{
_uint8 Local_Uint8Data;
DIO_VoidInit();
UART_VoidInit();
while(TRUE){
UART_CheckStatusRxData(&Local_Uint8Data);
	if(Local_Uint8Data == 'a')
   {
      DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN0,DIO__UINT8_HIGH);
      UART_CheckStatusTxStringSynchWithBlocking("ELABBAS");
   }
   else if (Local_Uint8Data == 'b')
   {
	   DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN0,DIO__UINT8_LOW);
   }
}
	return 0;
}


