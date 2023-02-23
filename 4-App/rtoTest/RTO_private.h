/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  24/10/2020  ****************/
/*************** SWC      :    RTO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct RTO_private
{
        _uint16 Priodicity;
       
        _uint16 FristDelay;

        Void (*PTF)(Void);
}TCB;



#endif
