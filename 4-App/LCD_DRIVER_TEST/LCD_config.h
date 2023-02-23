/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	23/8/2020	****************************************************/
/*********	SWC		:	LCD			****************************************************/
/*********	Version	:	V1.0		****************************************************/
/***************************************************************************************/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/***

OPTIONS : 

For Ports :

1- DIO_PORTA_ID
2- DIO_PORTB_ID
3- DIO_PORTC_ID
4- DIO_PORTD_ID

For Pins :

1- PIN0
2- PIN1
3- PIN2
4- PIN3
5- PIN4
6- PIN5
7- PIN6
8- PIN7


****/

#define LCD_DATA_PORT		DIO_PORTD_ID

#define LCD_CONTROL_PORT	DIO_PORTA_ID
#define LCD_RS_PIN			PIN0
#define LCD_RW_PIN			PIN1
#define LCD_E_PIN			PIN2


#endif
