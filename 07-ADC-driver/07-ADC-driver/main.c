/*
 * main.c
 *
 *  Created on: May 21, 2022
 *      Author: mazen
 */


#include "STD_TYPES.h"
#include "ADC/ADC_interface.h"
#include "LCD/LCD_interface.h"

int main(void)
{
	LCD_Init();
	ADC_Init();
	u16 digital_val = 0;
	u16 Temperature = 0;
	while(1)
	{
		digital_val = ADC_ReadDigitalValue(0);
		Temperature = (500*digital_val)/1024 ;
		LCD_SendCommand(LCD_CLEAR);
//		LCD_PrintNumber(digital_val);
		LCD_PrintNumber(Temperature);
		_delay_ms(1000);
	}

}
