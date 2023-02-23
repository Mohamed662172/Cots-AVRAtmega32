/*
 * ADC_program.c
 *
 *  Created on: May 21, 2022
 *      Author: mazen
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void (*ADC_Callback)(void) ;



void ADC_Init(void)
{
	// Vref selection
	SET_BIT(ADMUX, 6); //AVCC
	//left Adjust
#if ADC_LEFT_ADJUST==RIGHT_ADJUST
	CLR_BIT(ADMUX, ADLAR);
#elif ADC_LEFT_ADJUST==LEFT_ADJUST
	SET_BIT(ADMUX, ADLAR);
#endif
	// Auto trigger Enable
	CLR_BIT(ADCSRA, 5);
	// Interrupt enable
	CLR_BIT(ADCSRA, 3);
	// Prescaler
	ADCSRA &=~(0b111); // clear for Prescaler bits
	ADCSRA |= (0b110); // set Prescaler to 64
	// Enable ADC
	SET_BIT(ADCSRA, ADEN);
}

u16  ADC_ReadDigitalValue(u8 ChannelNo)
{


	/* 1- Select Channel */
	ADMUX = (ADMUX & ~(0b00011111)) | ChannelNo  ;
	/* 2- start conversion */
	SET_BIT(ADCSRA, ADSC);
	/* 3- Polling on the ADC interrupt flag*/
	while(GET_BIT(ADCSRA, ADIF) == 0){}
	/* 4- Clear ADC interrupt flag  */
	SET_BIT(ADCSRA, ADIF);
	/* 5- return ADC digital value  */
	return ADC_DATA;
}

void ADC_SetCallback( void (*fptr)(void))
{
	ADC_Callback =fptr;
}

void __vector_x(void) __attribute__((signal));
void __vector_x(void)
{
	ADC_Callback();
}
















