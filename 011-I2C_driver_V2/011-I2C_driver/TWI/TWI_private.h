/*
 * TWI_private.h
 *
 *  Created on: Jun 13, 2022
 *      Author: mazen
 */

#ifndef TWI_TWI_PRIVATE_H_
#define TWI_TWI_PRIVATE_H_

#define TWBR  *((volatile u8*)(0x20))
#define TWCR  *((volatile u8*)(0x56))
#define TWSR  *((volatile u8*)(0x21))
#define TWDR  *((volatile u8*)(0x23))
#define TWAR  *((volatile u8*)(0x22))


#endif /* TWI_TWI_PRIVATE_H_ */
