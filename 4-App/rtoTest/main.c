/*

 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL Layer */
#include"DIO_interface.h"

/*SERV layer */
#include"RTO_interface.h"

Void  App_VoidTask3(Void);
Void  App_VoidTask2(Void);
Void  App_VoidTask1(Void);

int main (void)
{

DIO_VoidInit();

RTO_CheckStatusCreateTask(1,10000,0,&App_VoidTask1);
RTO_CheckStatusCreateTask(2,2000,0,&App_VoidTask2);
RTO_CheckStatusCreateTask(0,50000,0,&App_VoidTask3);

RTO_VoidInit();

RTO_VoidStartTmr(1);

while(TRUE);
	return 0;
}

Void  App_VoidTask1(Void)
{
static _uint8 Flag = 0;

if(Flag == 0)
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_HIGH);
	Flag= 1;
}
else
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN1,DIO__UINT8_LOW);
	Flag= 0;

}

}
Void  App_VoidTask2(Void)
{
static _uint8 Flag = 0;

if(Flag == 0)
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN2,DIO__UINT8_HIGH);
	Flag= 1;
}
else
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN2,DIO__UINT8_LOW);
	Flag= 0;

}

}
Void  App_VoidTask3(Void)
{
static _uint8 Flag = 0;

if(Flag == 0)
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_HIGH);
	Flag= 1;
}
else
{
	DIO__CheckStatusSetPinValue(DIO__UINT8_PORTA,DIO__UINT8_PIN3,DIO__UINT8_LOW);
	Flag= 0;

}

}
