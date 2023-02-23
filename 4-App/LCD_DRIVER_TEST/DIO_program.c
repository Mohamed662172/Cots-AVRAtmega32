/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/8/2020	****************************************************/
/*********	SWC		:	DIO			****************************************************/
/*********	Version	:	V1.0		****************************************************/
/***************************************************************************************/

/* INCLUDES */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/************/

void DIO_u8PortsInit(void)
{
	/******** DIRECTION INITIALIZATION ***********/

	DDRA_REG = CONC( DIO_PA7_DIRECTION_INIT , DIO_PA6_DIRECTION_INIT , DIO_PA5_DIRECTION_INIT , DIO_PA4_DIRECTION_INIT
			   , DIO_PA3_DIRECTION_INIT , DIO_PA2_DIRECTION_INIT , DIO_PA1_DIRECTION_INIT , DIO_PA0_DIRECTION_INIT ) ;

	DDRB_REG = CONC( DIO_PB7_DIRECTION_INIT , DIO_PB6_DIRECTION_INIT , DIO_PB5_DIRECTION_INIT , DIO_PB4_DIRECTION_INIT 
			   , DIO_PB3_DIRECTION_INIT , DIO_PB2_DIRECTION_INIT , DIO_PB1_DIRECTION_INIT , DIO_PB0_DIRECTION_INIT ) ;

	DDRC_REG = CONC( DIO_PC7_DIRECTION_INIT , DIO_PC6_DIRECTION_INIT , DIO_PC5_DIRECTION_INIT , DIO_PC4_DIRECTION_INIT 
			   , DIO_PC3_DIRECTION_INIT , DIO_PC2_DIRECTION_INIT , DIO_PC1_DIRECTION_INIT , DIO_PC0_DIRECTION_INIT ) ;  

	DDRD_REG = CONC( DIO_PD7_DIRECTION_INIT , DIO_PD6_DIRECTION_INIT , DIO_PD5_DIRECTION_INIT , DIO_PD4_DIRECTION_INIT 
			   , DIO_PD3_DIRECTION_INIT , DIO_PD2_DIRECTION_INIT , DIO_PD1_DIRECTION_INIT , DIO_PD0_DIRECTION_INIT ) ;

	/******** VALUE INITIALIZATION ***************/

	PORTA_REG = CONC( DIO_PA7_LOGIC_INIT , DIO_PA6_LOGIC_INIT , DIO_PA5_LOGIC_INIT , DIO_PA4_LOGIC_INIT
			    , DIO_PA3_LOGIC_INIT , DIO_PA2_LOGIC_INIT , DIO_PA1_LOGIC_INIT , DIO_PA0_LOGIC_INIT) ;

	PORTB_REG = CONC( DIO_PB7_LOGIC_INIT , DIO_PB6_LOGIC_INIT , DIO_PB5_LOGIC_INIT , DIO_PB4_LOGIC_INIT
			    , DIO_PB3_LOGIC_INIT , DIO_PB2_LOGIC_INIT , DIO_PB1_LOGIC_INIT , DIO_PB0_LOGIC_INIT) ;

	PORTC_REG = CONC( DIO_PC7_LOGIC_INIT , DIO_PC6_LOGIC_INIT , DIO_PC5_LOGIC_INIT , DIO_PC4_LOGIC_INIT
			    , DIO_PC3_LOGIC_INIT , DIO_PC2_LOGIC_INIT , DIO_PC1_LOGIC_INIT , DIO_PC0_LOGIC_INIT) ;

	PORTD_REG = CONC( DIO_PD7_LOGIC_INIT , DIO_PD6_LOGIC_INIT , DIO_PD5_LOGIC_INIT , DIO_PD4_LOGIC_INIT
			    , DIO_PD3_LOGIC_INIT , DIO_PD2_LOGIC_INIT , DIO_PD1_LOGIC_INIT , DIO_PD0_LOGIC_INIT) ;

}


u8 DIO_u8SetPortDir(u8 Copy_u8PortId , u8 Copy_u8PortDir)
{
	u8 Local_u8ErrorStatus= OK ;
	if(Copy_u8PortId <= 3 && Copy_u8PortDir <= 255)
	{

		switch(Copy_u8PortId)
		{
			case DIO_PORTA_ID : 
			DDRA_REG = Copy_u8PortDir ;
			break;
	
			case DIO_PORTB_ID :
			DDRB_REG = Copy_u8PortDir ;
			break ;

			case DIO_PORTC_ID : 
			DDRC_REG = Copy_u8PortDir ;
			break;

			case DIO_PORTD_ID :
			DDRD_REG = Copy_u8PortDir ;
			break ;
		}
	}	
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus ;
}

u8 DIO_u8SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorStatus= OK ;
	if(Copy_u8PortId <= 3 && Copy_u8PortValue <= 255)
	{

		switch(Copy_u8PortId)
		{
			case DIO_PORTA_ID : 
			PORTA_REG = Copy_u8PortValue ;
			break;
	
			case DIO_PORTB_ID :
			PORTB_REG = Copy_u8PortValue ;
			break ;
	
			case DIO_PORTC_ID : 
			PORTC_REG = Copy_u8PortValue ;
			break;
	
			case DIO_PORTD_ID :
			PORTD_REG = Copy_u8PortValue ;
			break ;
		}
	}	
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus ;	
}

u8 DIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue )
{
	u8 Local_u8ErrorStatus= OK ;
	if(Copy_u8PortId <= 3 && Copy_u8PinId <= 7 && Copy_u8PinValue <= 1)
	{
		switch(Copy_u8PortId)
		{
			case DIO_PORTA_ID :
				switch(Copy_u8PinValue)
				{
				case OUTPUT_LOW :
				CLR_BIT(PORTA_REG,Copy_u8PinId);
				break ;
	
				case OUTPUT_HIGH:
				SET_BIT(PORTA_REG,Copy_u8PinId);
				break ;
				}
	
			break ; 
	
			case DIO_PORTB_ID :
				switch(Copy_u8PinValue)
				{
				case OUTPUT_LOW :
				CLR_BIT(PORTB_REG,Copy_u8PinId);
				break ;
	
				case OUTPUT_HIGH:
				SET_BIT(PORTB_REG,Copy_u8PinId);
				break ;
				}
			break ;
	
			case DIO_PORTC_ID :
				switch(Copy_u8PinValue)
				{
				case OUTPUT_LOW :
				CLR_BIT(PORTC_REG,Copy_u8PinId);
				break ;
	
				case OUTPUT_HIGH:
				SET_BIT(PORTC_REG,Copy_u8PinId);
				break ;
				}
			break ; 
			case DIO_PORTD_ID :
				switch(Copy_u8PinValue)
				{
				case OUTPUT_LOW :
				CLR_BIT(PORTD_REG,Copy_u8PinId);
				break ;
	
				case OUTPUT_HIGH:
				SET_BIT(PORTD_REG,Copy_u8PinId);
				break ;
				}
			break ;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus ;	
}


u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 *Pu8ReturnedPinValue )
{
	u8 Local_u8ErrorStatus = OK ;

	if(Copy_u8PortId <= 3 && Copy_u8PinId <= 7 && Pu8ReturnedPinValue != NULL )
	{
		switch(Copy_u8PortId)
		{
			case DIO_PORTA_ID :
			*Pu8ReturnedPinValue = GET_BIT(PINA_REG,Copy_u8PinId);
			break ;
		}
		switch(Copy_u8PortId)
		{
			case DIO_PORTB_ID :
			*Pu8ReturnedPinValue = GET_BIT(PINB_REG,Copy_u8PinId);
			break ;
		}
		switch(Copy_u8PortId)
		{
			case DIO_PORTC_ID :
			*Pu8ReturnedPinValue = GET_BIT(PINC_REG,Copy_u8PinId);
			break ;
		}
		switch(Copy_u8PortId)
		{
			case DIO_PORTD_ID :
			*Pu8ReturnedPinValue = GET_BIT(PIND_REG,Copy_u8PinId);
			break ;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;
}


u8 DIO_u8TogglePinValue(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	u8 Local_u8ErrorStatus = OK ;

	if (Copy_u8PortId <= 3 && Copy_u8PinId <= 7 )
	{
		switch(Copy_u8PortId)
		{
			case DIO_PORTA_ID :
			TOG_BIT(PORTA_REG,Copy_u8PinId);
			break ;

			case DIO_PORTB_ID :
			TOG_BIT(PORTB_REG,Copy_u8PinId);
			break ;

			case DIO_PORTC_ID :
			TOG_BIT(PORTC_REG,Copy_u8PinId);
			break ;

			case DIO_PORTD_ID :
			TOG_BIT(PORTD_REG,Copy_u8PinId);
			break ;
		}
	}
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus ;
}





