/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/05/2020  ****************/
/*************** SWC      :    DIO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/
#ifndef  DIO_PRIVATE_H
#define  DIO_PRIVATE_H


/* Macros For HW Registers*/

#define PORTA__UINT8_REG     *(  (volatile  _uint8* const) 0x3B)
#define DDRA__UINT8_REG      *(  (volatile  _uint8* const) 0x3A)
#define PINA__UINT8_REG      *(  (volatile  _uint8* const) 0x39)

#define PORTB__UINT8_REG     *(  (volatile  _uint8* const) 0x38)
#define DDRB__UINT8_REG      *(  (volatile  _uint8* const) 0x37)
#define PINB__UINT8_REG      *(  (volatile  _uint8* const) 0x36)

#define PORTC__UINT8_REG     *(  (volatile  _uint8* const) 0x35)
#define DDRC__UINT8_REG      *(  (volatile  _uint8* const) 0x34)
#define PINC__UINT8_REG      *(  (volatile  _uint8* const) 0x33)

#define PORTD__UINT8_REG     *(  (volatile  _uint8* const) 0x32)
#define DDRD__UINT8_REG      *(  (volatile  _uint8* const) 0x31)
#define PIND__UINT8_REG      *(  (volatile  _uint8* const) 0x30)


/* Macros For Direction of THe Pins in Config file */
#define DIO__UINT8_INITIAL_INPUT              0
#define DIO__UINT8_INITIAL_OUTPUT             1

/* Macros For Value of THe Pins in Config file */
#define   DIO__UINT8_INPUT_FLOATING     0  
#define	  DIO__UINT8_INPUT_PULLUP       1
#define	  DIO__UINT8_OUTPUT_LOW          0
#define   DIO__UINT8_OUTPUT_HIGH          1

/* Macros Contcatenate Function */
#define   CONC(B7,B6,B5,B4,B3,B2,B1,B0)               CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 
#define   CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)          0b##B7##B6##B5##B4##B3##B2##B1##B0












#endif
