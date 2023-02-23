/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#include"Std_Types.h"
#include"Bit_Math.h"
#define F_CPU  8000000UL
#include "util/delay.h"


#include"DIO_interface.h"
#include"EXTI_interface.h"
#include"GIE_interface.h"
#include"TMR_interface.h"
#include"LCD_interface.h"

Void App_voidICUInterrupt(Void);
_uint16 APP_uint16OnPeriod,APP_uint16OffPeriod;
int main ()
{
_uint32 Local_uint32TotalPeriod;
_uint8  Local_uint8DutyCycle;
 /*Dio init */
DIO_VoidInit();
 /* Activate global interrupt*/
GIE_VoidEnable();
/*set call back function*/
EXTI_CheckStatusSetCallBackFunc(&App_voidICUInterrupt,INT0);
/* Activate external interrupt */
EXIT_CheckStatusExtIntEnable(INT0,EXIT_UINT8_RIASING_EDGE);
/* turn timer one*/
TMR_VoidTimer1INIT();
/*set Duty Cycle of PWM*/
TMR_VOidTimer1SEtCompareMatchValue(127);
/* start timer 0*/
TMR_CheckSatusInit(0);

/* LCD init */
LCD_VoidInit4bit();

while(TRUE)
{
	Local_uint32TotalPeriod = APP_uint16OnPeriod + APP_uint16OffPeriod;
	Local_uint8DutyCycle =  (_uint8)((APP_uint16OnPeriod*100UL)/(Local_uint32TotalPeriod));
	LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
	LCD_CheckStatusWriteString("Duty= ");
	LCD_CheckStatusSendNumber(Local_uint8DutyCycle);
	LCD_CheckStatusWriteString("%");
	LCD_CheckStatusGoToXY(LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER0);
	LCD_CheckStatusWriteString("TP= ");
	LCD_CheckStatusSendNumber(Local_uint32TotalPeriod);
	LCD_CheckStatusWriteString("uSec");

}

return 0 ;
}
Void App_voidICUInterrupt(Void)
{
    _uint16 Local_Uint16TimerValue;
    static _uint8 Local_Uint8Flag = 0 ;
    static _uint16 Local_Uint16TempTimerValue = 0 ;
    /*Read Timer*/
    TMR_CheckStatusGetCounterTimer1Value(&Local_Uint16TimerValue);

    if(Local_Uint8Flag == 0)/* Raising edge*/
    {
    	APP_uint16OffPeriod = Local_Uint16TimerValue - Local_Uint16TempTimerValue;
    	/* Change mode sense  Control into Falling edge*/
    	EXIT_CheckStatusExtIntEnable(INT0,EXIT_UINT8_FALLING_EDGE);
    	/* change flag into falling edge */
    	Local_Uint8Flag = 1;
    }
    else /* falling edge*/
    {
    	APP_uint16OnPeriod = Local_Uint16TimerValue - Local_Uint16TempTimerValue;
    	/* Change mode sense  Control into Falling edge*/
    	EXIT_CheckStatusExtIntEnable(INT0,EXIT_UINT8_RIASING_EDGE);
    	/* change flag into raising edge */
      	Local_Uint8Flag = 0;
    }
    Local_Uint16TempTimerValue = Local_Uint16TimerValue;

}
