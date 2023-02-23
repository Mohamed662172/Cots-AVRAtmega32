/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  17/09/2020  ****************/                                                                          
/*************** SWC      :   EXTI       ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/  
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI__UINT8_MCUCR_REG      *(  (volatile  _uint8* const) 0x55)
#define EXTI__UINT8_MCUCSR_REG     *(  (volatile  _uint8* const) 0x54)
#define EXTI__UINT8_GICR_REG       *(  (volatile  _uint8* const) 0x5B)
#define EXTI__UINT8_GIFR_REG       *(  (volatile  _uint8* const) 0x5A)


#define  GICR_INT1   7
#define  GICR_INT0   6
#define  GICR_INT2   5

#define  MCUCR_ISC00  0
#define  MCUCR_ISC01  1
#define  MCUCR_ISC10  2
#define  MCUCR_ISC11  3

#define MCUCSR_ISC2   6




#endif