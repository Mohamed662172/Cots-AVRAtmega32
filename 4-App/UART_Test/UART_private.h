/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  09/10/2020  ****************/
/*************** SWC      :   UART       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define  UART_UBRRH_UINT8__REG      *((volatile _uint8* const)0x40)
#define  UART_UBRRL_UINT8__REG      *((volatile _uint8* const)0x29)
#define  UART_UCSRC_UINT8__REG      *((volatile _uint8* const)0x40)
#define  UART_UDR_UINT8__REG        *((volatile _uint8* const)0x2C)
#define  UART_UCSRA_UINT8__REG      *((volatile _uint8* const)0x2B)
#define  UART_UCSRB_UINT8__REG      *((volatile _uint8* const)0x2A)






#endif