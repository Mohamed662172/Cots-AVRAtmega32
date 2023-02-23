/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  24/10/2020  ****************/
/*************** SWC      :    RTO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_

CheckStatus RTO_CheckStatusCreateTask(_uint8 Copy__Uint8Priority, _uint16 Copy__Uint16Priodicity,_uint16 Copy__Uint16FristDelay,void (*PTF)(Void));

Void RTO_VoidInit(Void);

Void RTO_VoidStartTmr(_uint16 Copy_Uint16TmrInMsec);

#endif
