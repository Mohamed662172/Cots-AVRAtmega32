/*
 * motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
/*  LIBERARY LAYER */
#include "Std_Types.h"
#include"Bit_Math.h"
#define F_CPU   8000000UL
#include <util/delay.h>
/* MCAL LAYER */
#include"DIO_interface.h"
/*HAL LAYER */
#include"LCD_interface.h"
#include"KPAD_interface.h"
#include"STEP_interface.h"
Void ConvertCharToInteger(_uint8 *Copy_Uint8Char);
_uint8 Login_Sys(Void);
_uint8 Check_Login(Void);
Void   sys_option(Void);
Void START_SYS(Void);
Void END_SYS(Void);
_uint8 Local__Uint8Arr[4];




int main(){

START_SYS();
while(TRUE)
{
}
	return 0 ;
}

Void START_SYS(Void)
{


	_uint8 Local__Uint8Var;
	 DIO_VoidInit();
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN6,DIO__UINT8_HIGH);
	 LCD_VoidInit4bit();

	 LCD_VoidClearDisplay();
    _delay_ms(500);
    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER3);
	 LCD_CheckStatusWriteString("<Press 'A' To Start System >");
	 LCD_VoidShiftRight(16,250);
for(int i=0;i<1;){

	KPAD_CheckStatusGetKey(&Local__Uint8Var);

	if(Local__Uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
    {

      LCD_VoidClearDisplay();
   if(Local__Uint8Var == 'A')
        {



    	 Check_Login();

    	 _delay_ms(500);
    	 sys_option();

++i;
      }
    }
  }
}
Void ConvertCharToInteger(_uint8 *Copy_Uint8Char)
{
	*Copy_Uint8Char=*Copy_Uint8Char-'0';

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

	LCD_CheckStatusWriteString("Welcome to DashBoard");
while(TRUE){
    LCD_VoidShiftRight(36,350);

    break;
}
}
else if(LocalReturnValue== 0)
{
LCD_CheckStatusWriteString("Wrong!");
while(TRUE){
LCD_CheckStatusShiftRightOrLeft(350);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_LOW);
_delay_ms(500);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_HIGH);
_delay_ms(500);

}


}
return 0 ;
}

Void sys_option(Void)
{
   _uint8 Local_Uint8StepDir;
   _uint8 Local__Uint8Var;
   _uint16 Local__Uint16Angel;

   LCD_VoidClearDisplay();
   LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
   LCD_CheckStatusWriteString("1-DC_Motor");
   LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER0);
   LCD_CheckStatusWriteString("2-Stepper_Motor");
   LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER10);
   LCD_CheckStatusWriteString("3-Exit!");
for(int r=0;r<3;)
{
   KPAD_CheckStatusGetKey(&Local__Uint8Var);
  	   if(Local__Uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
  	    {

          switch(Local__Uint8Var){
          case  '1':
              LCD_VoidClearDisplay();
              LCD_CheckStatusWriteString("Direction:");
              LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER0);
              LCD_CheckStatusWriteString("1-CW");
              LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER5);
              LCD_CheckStatusWriteString("2-CCW");
              LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER11);
              LCD_CheckStatusWriteString("3-Stop");
              for(int s=0;s<1;){
                KPAD_CheckStatusGetKey(&Local_Uint8StepDir);
                if(Local_Uint8StepDir != KPAD__UINT8_KEY_NOT_PRESSED)
                {

                    switch(Local_Uint8StepDir)
                    {
                    case '1':
                      	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_HIGH);
                      	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_LOW);
                     s++;
                    break;
                    case '2':
                      	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_LOW);
                      	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_HIGH);
                     s++;
                    break;
                    case '3':
                      	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_LOW);
                      	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_LOW);
                     s++;
                    break;
                    default:

                    break;
                    }
        	     }
              }
              sys_option();
        	  ++r;
             break;
          case  '2':
              LCD_VoidClearDisplay();
        	  for(int i = 0 ; i < 3; ++i){
    			  LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
                  LCD_CheckStatusWriteString("Angel:");
                  LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER6+i);
        		  while(LCD__UINT8_LOCATION_NUMBER6+i<=8)
        		  {
                      KPAD_CheckStatusGetKey(&Local__Uint8Var);
        		    if(Local__Uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
        		     {

        		    	Local__Uint8Arr[i]=Local__Uint8Var;
                        LCD_CheckStatusSendChar4bit(Local__Uint8Var);

                         ++i;

        		     }

        		  }

                  if(i==3){
                   LCD_CheckStatusSpecialChar(1,LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER9);
                   LCD_CheckStatusDisplaySpecialChar(1);
                   _delay_ms(500);
                  }
                  }

                  for(int j=0;j<3;++j)
                  {
                     ConvertCharToInteger(&Local__Uint8Arr[j]);
                      Local__Uint16Angel=(_uint16)(Local__Uint8Arr[0]*100+Local__Uint8Arr[1]*10+Local__Uint8Arr[2]*1);
                  }
                LCD_VoidClearDisplay();
                LCD_CheckStatusWriteString("Direction:");
                LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER0);
                LCD_CheckStatusWriteString("1-CW");
                LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER7);
                LCD_CheckStatusWriteString("2-CCW");
              for(int k=0;k<1;){
                KPAD_CheckStatusGetKey(&Local_Uint8StepDir);
                if(Local_Uint8StepDir != KPAD__UINT8_KEY_NOT_PRESSED)
                {

                    switch(Local_Uint8StepDir)
                    {
                    case '1':

                     STEP_CheckStatusStepperMotorRottor(Local__Uint16Angel,CLK_WISE);
                     k++;
                    break;
                    case '2':
                    STEP_CheckStatusStepperMotorRottor(Local__Uint16Angel,COUNTER_CLK_WISE);
                     k++;
                    break;
                    default:

                    break;
                    }
        	     }
              }
              sys_option();
              ++r;
        	  break;
          case  '3':
            	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_LOW);
            	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_LOW);
        	  LCD_VoidClearDisplay();
        	  LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER3);
        	  LCD_CheckStatusWriteString("Thanks");
        	  LCD_CheckStatusSpecialChar(2,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER5);
        	  LCD_CheckStatusDisplaySpecialChar(2);
        	  LCD_CheckStatusSpecialChar(3,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER6);
        	  LCD_CheckStatusDisplaySpecialChar(3);
              LCD_VoidShiftRight(16,350);
              END_SYS();
        	  ++r;
             break;
          default:

        	  break;
          }
  	    }

   }
}
Void END_SYS(Void)
{
	_uint8 Local__Uint8Var;
	 DIO_VoidInit();

	 LCD_VoidInit4bit();

	 LCD_VoidClearDisplay();
    _delay_ms(500);
    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER3);
	 LCD_CheckStatusWriteString("<Press 'C' To END System >");
	 LCD_VoidShiftRight(16,350);
for(int i=0;i<1;){

	KPAD_CheckStatusGetKey(&Local__Uint8Var);

	if(Local__Uint8Var != KPAD__UINT8_KEY_NOT_PRESSED)
    {

      LCD_VoidClearDisplay();
   if(Local__Uint8Var == 'C')
        {

        DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN6,DIO__UINT8_LOW);
        ++i;
      }
    }
  }
}


