/*
 * TWI_interface.h
 *
 *  Created on: Jun 13, 2022
 *      Author: mazen
 */

#ifndef TWI_TWI_INTERFACE_H_
#define TWI_TWI_INTERFACE_H_

#define TWI_WRITE		0
#define TWI_READ		1
#define TWI_ACK			1
#define TWI_NACK		0




#define TWI_START_CONDITON_SENT		  0x08
#define TWI_REP_START_CONDITON_SENT   0x10



void TWI_Init(void);
void TWI_SendStartCondition(void);
void TWI_SendSlaveAddress(u8 sla, u8 rw);
void TWI_SendData(u8 byte);
u8   TWI_ReadData(u8 ack);
void TWI_SendRepeatedStart(void);
void TWI_SendStopCondition(void);
u8   TWI_GetStatusCode(void);



#endif /* TWI_TWI_INTERFACE_H_ */
