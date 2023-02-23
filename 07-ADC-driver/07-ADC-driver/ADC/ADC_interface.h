/*
 * ADC_interface.h
 *
 *  Created on: May 21, 2022
 *      Author: mazen
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_


void ADC_Init(void);
u16  ADC_ReadDigitalValue(u8 ChannelNo);

void ADC_SetCallback( void (*fptr)(void));

void ADC_StartConversion(u8 ChannelNo);




#endif /* ADC_ADC_INTERFACE_H_ */
