/*
 * TWI_program.c
 *
 *  Created on: Jun 13, 2022
 *      Author: mazen
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_Init(void)
{
	/* Bit rate + prescaler  */
	TWBR = 32 ;
	TWSR |= (TWI_PRESCALER);
	/* Own slave address */
	TWAR = TWI_OWN_SLA ;
}

void TWI_SendStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|
	(1<<TWEN);

	while (!(TWCR & (1<<TWINT)))
	;
}

void TWI_SendSlaveAddress(u8 sla, u8 rw)
{
	TWDR = (sla<<1) | rw ;
	CLR_BIT(TWCR, TWSTA); // clear start bit before continue of communication
	TWCR = (1<<TWINT) | (1<<TWEN);

	while (!(TWCR & (1<<TWINT)))
		;
}

void TWI_SendData(u8 byte)
{
	TWDR = byte ;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while (!(TWCR & (1<<TWINT)))
		;
}

u8   TWI_ReadData(u8 ack)
{
	if(ack == TWI_ACK)
	{
		SET_BIT(TWCR, TWEA);
	}
	else if(ack== TWI_NACK)
	{
		CLR_BIT(TWCR, TWEA);
	}


	while (!(TWCR & (1<<TWINT)))
			;

	return TWDR ;
}

void TWI_SendRepeatedStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|
		(1<<TWEN);

		while (!(TWCR & (1<<TWINT)))
		;
}

void TWI_SendStopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|
	(1<<TWSTO);
}

u8   TWI_GetStatusCode(void)
{
	return (TWSR & 0xF8) ;
}
