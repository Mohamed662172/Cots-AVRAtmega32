/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#define F_CPU    8000000UL
#include<util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

/* Mcal */
#include"DIO_interface.h"
#include"ADC_interface.h"



/*  Hal */
#include"LCD_interface.h"

int main(Void){
_uint16 Local_U16DigitValue,Local_U16AnalogValue,Local_Uint16TempValue;

DIO_VoidInit();
LCD_VoidInit4bit();
ADC_VoidInit();
LCD_CheckStatusWriteString("Hello");
while(TRUE)
{

  /*

  	ADC_CheckStatusGetDigigtalValue(ADC_CHANNEL_0,&Local_U16DigitValue);
	Local_U16AnalogValue =(_uint16)(((_uint32)Local_U16DigitValue * 5000UL)/1024);
	   if(Local_U16AnalogValue<= 355)
	    {
	        DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_HIGH);
	        DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_LOW);
	    }
	    else if (Local_U16AnalogValue > 355U )
	    {
	    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_LOW);
	    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
	    }
	    _delay_ms(100);
	    DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_LOW);
	    DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_LOW);
   */

}

	return 0 ;
}


/*
   if(Local_U16AnalogValue<= 1500)
    {
        DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_HIGH);
        DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_LOW);
        DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN2,DIO__UINT8_LOW);
    }
    else if ((Local_U16AnalogValue > 1500U) && (Local_U16AnalogValue <= 3000U))
    {
    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_LOW);
    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN2,DIO__UINT8_LOW);

	}
    else if(Local_U16AnalogValue > 3000U)
    {
    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_LOW);
    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_LOW);
    	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN2,DIO__UINT8_HIGH);
    }
    _delay_ms(100);
    DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN0,DIO__UINT8_LOW);
    DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN1,DIO__UINT8_LOW);
    DIO__CheckStatusSetPinValue(DIO__UINT8_PORTB,DIO__UINT8_PIN2,DIO__UINT8_LOW);
  */
/*
  	LCD_CheckStatusWriteString("TEMP: ");
    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER9);
    LCD_CheckStatusWriteString("*C");

  	ADC_CheckStatusGetDigigtalValue(ADC_CHANNEL_3,&Local_U16DigitValue);
	Local_U16AnalogValue =(_uint16)(((_uint32)Local_U16DigitValue * 5000UL)/1024);
	Local_Uint16TempValue = (Local_U16AnalogValue/10);

	LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER6);
	LCD_CheckStatusSendNumber(Local_Uint16TempValue);
	_delay_ms(1000);
 */
