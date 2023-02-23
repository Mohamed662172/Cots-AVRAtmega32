/*
 * testINT0.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */



/* Liberary Layer */
#include"Bit_Math.h"
#include"Std_Types.h"
#define F_CPU  8000000UL
#include<util/delay.h>

/* mcal */
#include"DIO_interface.h"
/* HAL */
#include"LCD_interface.h"
#include"KPAD_interface.h"
#include"EXTI_interface.h"
#include"GIE_interface.h"

Void Turnon(Void);
_uint8 Login_Sys(Void);
_uint8 Check_Login(Void);
Void ConvertCharToInteger(_uint8 *Copy_Uint8Char);
_uint8 Local__Uint8Arr[4];

int main(){

DIO_VoidInit();

LCD_VoidInit4bit();

/* Enable EXTRnal interrupt number 0 */

GIE_VoidEnable();

EXTI_CheckStatusSetCallBackFunc(&Turnon,INT0);

EXIT_CheckStatusExtIntEnable(INT0,EXIT_UINT8_FALLING_EDGE);

_delay_ms(500);

for(int  i =1 ;i<=3;++i)
{

   LCD_CheckStatusSendChar4bit('0'+i);

   _delay_ms(1000);

   LCD_VoidClearDisplay();
_delay_ms(1000);

}

Check_Login();

while(TRUE)
{

}


	return  0 ;
}


Void ConvertCharToInteger(_uint8 *Copy_Uint8Char)
{
	*Copy_Uint8Char=*Copy_Uint8Char-'0';

}

Void Turnon(Void)
{
		static _uint8 Local__Uint8Flag=0;

if(Local__Uint8Flag == 0)
{
      DIO__CheckStatusSetPinValue(DIO__UINT8_PORTD,DIO__UINT8_PIN3,DIO__UINT8_HIGH);
      Local__Uint8Flag =1;
}
else
{
	 DIO__CheckStatusSetPinValue(DIO__UINT8_PORTD,DIO__UINT8_PIN3,DIO__UINT8_LOW);
     Local__Uint8Flag=0;
}


}



_uint8 Login_Sys(Void)
{
	_uint16 Local__Uint16Var2;
	_uint8 Local__Uint8Var;

	for(int j=0;j<3;++j){
		LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
		LCD_CheckStatusWriteString("PASS:");

for(int i=0;i<4;){
		while(LCD__UINT8_LOCATION_NUMBER6+i<10)
		{
			LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER6+i);
	    KPAD_CheckStatusGetKey(&Local__Uint8Var);
	   if(Local__Uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
	    {

	     Local__Uint8Arr[i]=Local__Uint8Var;
		 LCD_CheckStatusSendChar4bit('*');
	     if(Local__Uint8Var == 'D')
	        {
	          LCD_VoidClearDisplay();
	        }
	        ++i;
	       }
	    }

	LCD_VoidClearDisplay();
	}
}
	for(int c=0;c<4;c++)
	{

          ConvertCharToInteger(&Local__Uint8Arr[c]);
          Local__Uint16Var2=(_uint16)(Local__Uint8Arr[0]*1000+Local__Uint8Arr[1]*100+Local__Uint8Arr[2]*10+Local__Uint8Arr[3]*1);

	}
	 if(1234==Local__Uint16Var2)
	          {
	          	_delay_us(1);
	          }
	          else
	          {
	             return 0;
	          }
	        return 1;

}


_uint8 Check_Login(Void)
{
	_uint8  LocalReturnValue;
	LocalReturnValue=Login_Sys();
if(LocalReturnValue==1)
{

LCD_CheckStatusWriteString("Good Morning There!!");

LCD_CheckStatusSpecialChar(2,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8);
LCD_CheckStatusDisplaySpecialChar(2);
LCD_CheckStatusSpecialChar(3,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER9);
LCD_CheckStatusDisplaySpecialChar(3);
LCD_VoidShiftRight(36,350);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTD,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
}
else if(LocalReturnValue== 0)
{
LCD_CheckStatusWriteString("Wrong!");
while(TRUE){
LCD_CheckStatusShiftRightOrLeft(350);
}
}
return 0 ;
}



