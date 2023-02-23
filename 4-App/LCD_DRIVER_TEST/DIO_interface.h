/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/8/2020	****************************************************/
/*********	SWC		:	DIO			****************************************************/
/*********	Version	:	V1.0		****************************************************/
/***************************************************************************************/

#ifndef  DIO_INTERFACE
#define  DIO_INTERFACE

/*** MACROS FOR DIO PINS ***/

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3	
#define PIN4		4	
#define PIN5		5
#define PIN6		6
#define PIN7		7

/***************************/

/*** MACROS FOR DIO PORTS IDs **/

#define DIO_PORTA_ID		0
#define DIO_PORTB_ID		1	
#define DIO_PORTC_ID		2 
#define DIO_PORTD_ID		3

/***************************/

/****** DIO DIRECTOINS *******/

#define INPUT		0
#define OUTPUT		1

/*****************************/

/****** DIO PORTS PIN VALUES *******/

#define OUTPUT_LOW		0
#define OUTPUT_HIGH		1
#define FLOAT_INPUT		0
#define PULLUP_INPUT	1

/**********************************/


/***** DIO INTERFACE FUNCTIONS **********/

void DIO_u8PortsInit(void);

u8 DIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue );

u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 *Pu8ReturnedPinValue );

u8 DIO_u8SetPortDir(u8 Copy_u8PortId , u8 Copy_u8PortDir);

u8 DIO_u8SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortValue);

u8 DIO_u8TogglePinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);

/****************************************/














#endif	