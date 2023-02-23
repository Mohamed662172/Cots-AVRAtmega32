/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#include"Std_Types.h"
#include"Bit_Math.h"
#define F_CPU  8000000UL
#include<util/delay.h>

#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TMR_interface.h"
#include"ADC_interface.h"


Void APP_VoidTOgLed(Void);
int main(Void)
{
	_uint16  LOCAL_UINT16Value;
	_uint16  LOCAL_UINT16OCRValue;
	DIO_VoidInit();
	ADC_VoidInit();
	//  GIE_VoidEnable();
//    TMR_CheckStatusTimer0CTCSetCallBack(&APP_VoidTOgLed);
//    TMR_CheckSatusInit(0);
//    _uint8 count =0;

TMR_VoidTimer1INIT();
//TMR_VOidTimer1SEtCompareMatchValue(500);
while(TRUE)
{

ADC_CheckStatusGetDigigtalValueSynchNonBlocking(ADC_CHANNEL_0,&LOCAL_UINT16Value);

LOCAL_UINT16OCRValue =(((2000UL*LOCAL_UINT16Value)/1023)+500);

TMR_VOidTimer1SEtCompareMatchValue(LOCAL_UINT16OCRValue);

//TMR_CHANGE_OCRC0(count);
//count++;
//_delay_ms(50);
}
	return 0 ;
}
Void  APP_VoidTOgLed(Void)
{
      static _uint8 Local_Uint8Flag = 0 ;

      if(Local_Uint8Flag == 0)
      {
    	  DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
          Local_Uint8Flag = 1;
      }
      else
      {
    	  DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_LOW);
          Local_Uint8Flag = 0;
      }

}
