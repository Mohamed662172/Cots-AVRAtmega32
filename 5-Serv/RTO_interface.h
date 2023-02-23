/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  24/10/2020  ****************/
/*************** SWC      :    RTO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_

CheckStatus RTO_CheckStatusCreateTask(_uint8 Copy__Uint8Priority, _uint8 Copy__Uint8Priodicity,_uint8 Copy__Uint8FristDelay,void (*PTF)(Void));

Void RTO_VoidSchedular(Void);

Void RTO_VoidInit(Void);



#endif