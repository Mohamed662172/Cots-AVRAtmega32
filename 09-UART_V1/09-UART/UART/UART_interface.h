/*
 * UART_interface.h
 *
 *  Created on: Jun 10, 2022
 *      Author: mazen
 */

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_


void UART_Init(void);
void UART_Transmit(u8 byte);
u8	 UART_Recieve(void);



#endif /* UART_UART_INTERFACE_H_ */
