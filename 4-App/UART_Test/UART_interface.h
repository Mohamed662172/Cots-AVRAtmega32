/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  09/10/2020  ****************/
/*************** SWC      :   UART       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

Void UART_VoidInit(Void);

Void UART_VoidTxData(_uint8 Copy_Uint8TxData);

CheckStatus UART_CheckStatusRxData(_uint8 *Copy_Uint8RxData);

CheckStatus UART_CheckStatusTxStringSynchWithBlocking(_uint8 * Copy_Uint8TxString);

CheckStatus UART_CheckStatusRxStringSynchWithBlocking(_uint8 * Copy_Uint8RxString);

Void UART_VoidTxStringAsynch(Void (*Copy_PF_Notification)(Void));

Void UART_VoidRxStringAsynch(Void (*Copy_PF_Notification)(Void));





#endif