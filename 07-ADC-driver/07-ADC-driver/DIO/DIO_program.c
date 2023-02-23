/*
 * DIO_program.c
 *
 *  Created on: Apr 29, 2022
 *      Author: mazen
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_SetPinDirection(u8 PortNo, u8 PinNo, u8 direction)
{
	if(direction == DIO_OUTPUT)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			SET_BIT(DDRA, PinNo);
			break;
		case DIO_PORTB:
			SET_BIT(DDRB, PinNo);
			break;
		}
	}
	else if(direction == DIO_INPUT)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA, PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB, PinNo);
			break;
		}
	}
}

void DIO_SetPinValue(u8 PortNo, u8 PinNo, u8 value)
{
	if(value == DIO_HIGH)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			SET_BIT(PORTA, PinNo);
			break;
		case DIO_PORTB:
			SET_BIT(PORTB, PinNo);
			break;
		}
	}
	else if(value == DIO_LOW)
	{
		switch(PortNo)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, PinNo);
			break;
		}
	}
}

u8   DIO_GetPinValue(u8 PortNo, u8 PinNo)
{
	u8 pin_value = 0;

	switch(PortNo)
	{
	case DIO_PORTA:
		pin_value = GET_BIT(PINA, PinNo );
		break;
	case DIO_PORTB:
		pin_value = GET_BIT(PINB, PinNo);
		break;
	}
	return pin_value;
}

void DIO_SetPortDirection(u8 PortNo, u8 direction)
{
	switch(PortNo)
	{
	case DIO_PORTA:
		DDRA = direction ;
		break;
	}
}

void DIO_SetPortValue(u8 PortNo, u8 value)
{
	switch(PortNo)
	{
	case DIO_PORTA:
		PORTA = value ;
		break;
	case DIO_PORTB:
		PORTB = value ;
		break;
	case DIO_PORTC:
		PORTC = value ;
		break;
	}
}

u8   DIO_GetPortValue(u8 PortNo)
{
	u8 port_value = 0;

	switch(PortNo)
	{
	case DIO_PORTA:
		port_value = PINA ;
		break;
	case DIO_PORTB:
		port_value = PINB ;
		break;
	}

	return port_value;
}
