/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/8/2020	****************************************************/
/*********	SWC		:	DIO			****************************************************/
/*********	Version	:	V1.0		****************************************************/
/***************************************************************************************/

#ifndef  DIO_PRIVATE
#define  DIO_PRIVATE

/******* MACROS FOR DIO REGISTERS ********/
#define DDRA_REG		*((volatile u8 *)0x3A) 
#define DDRB_REG		*((volatile u8 *)0x37)
#define DDRC_REG		*((volatile u8 *)0x34)
#define DDRD_REG		*((volatile u8 *)0x31)	

#define PORTA_REG		*((volatile u8 *)0x3B)
#define PORTB_REG		*((volatile u8 *)0x38)
#define PORTC_REG		*((volatile u8 *)0x35)
#define PORTD_REG		*((volatile u8 *)0x32)

#define PINA_REG		*((volatile u8 *)0x39)
#define PINB_REG		*((volatile u8 *)0x36)
#define PINC_REG		*((volatile u8 *)0x33)
#define PIND_REG		*((volatile u8 *)0x30)

/******************************************/




/***** Concatenation Function for Port initializatioln ***********/

#define CONC(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)			CONC_HELP(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)

#define CONC_HELP(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)		0b##PIN7##PIN6##PIN5##PIN4##PIN3##PIN2##PIN1##PIN0

#endif	