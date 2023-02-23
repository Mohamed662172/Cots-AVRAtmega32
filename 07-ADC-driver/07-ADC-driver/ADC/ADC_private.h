/*
 * ADC_private.h
 *
 *  Created on: May 21, 2022
 *      Author: mazen
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_


#define LEFT_ADJUST			1
#define RIGHT_ADJUST		2

#define ADLAR		5
#define ADEN		7
#define ADSC		6
#define ADIF		4

#define ADMUX		*((volatile u8*)(0x27))
#define ADCSRA		*((volatile u8*)(0x26))
#define ADCH		*((volatile u8*)(0x25))
#define ADCL		*((volatile u8*)(0x24))
#define ADC_DATA	*((volatile u16*)(0x24))
#define SFIOR		*((volatile u8*)(0x50))




#endif /* ADC_ADC_PRIVATE_H_ */
