/*
 * povTest.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
/* LIB layer */
#include"Std_Types.h"
#include"Bit_Math.h"
#define F_CPU  8000000U
#include<util/delay.h>

/* McAL  Layer */

#include "DIO_interface.h"


/* Hal  layer */


/*
typedef enum SevenSegment{ZERO=0b00111111,ONE=0b00000110,TWO=0b01011011,THREE=0b0101111,FOUR=0b0150110,FIVE=0b01101101,SIX=0b01111101,SEVEN=0b00000111,EIGHT=0b01111111,NINE=0b01101111,DOT=0b5000000}Ssegment;

Ssegment Arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
*/
void FUN_LEFT(void);
void FUN_RIGHT(void);

int main (){

_uint8  Local__uint8ReadValue ;
DIO__CheckStatusInit();

while(TRUE)
{
	DIO__CheckStatusGetPinValue(DIO__UINT8_PORTC,DIO__UINT8_PIN0,&Local__uint8ReadValue);
	DIO__CheckStatusGetPinValue(DIO__UINT8_PORTC,DIO__UINT8_PIN1,&Local__uint8ReadValue);
if(Local__uint8ReadValue == DIO__UINT8_LOW )
{

FUN_LEFT();

}
if( Local__uint8ReadValue != DIO__UINT8_LOW)
{


FUN_RIGHT();

}

	return 0 ;
}

















void FUN_LEFT(void)
{
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN7,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN7,DIO__UINT8_LOW);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN6,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN6,DIO__UINT8_LOW);
_delay_ms(50);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_LOW);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_LOW);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_LOW);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN2,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN2,DIO__UINT8_LOW);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_LOW);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN0,DIO__UINT8_HIGH);
_delay_ms(50);
DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN0,DIO__UINT8_LOW);
_delay_ms(50);

}

void FUN_RIGHT(void)
{

	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN0,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN0,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN2,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN2,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN4,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN5,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN6,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN6,DIO__UINT8_LOW);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN7,DIO__UINT8_HIGH);
	_delay_ms(50);
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN7,DIO__UINT8_LOW);
	_delay_ms(50);
}


