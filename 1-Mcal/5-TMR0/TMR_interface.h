

#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

CheckStatus TMR_CheckSatusInit( _uint16 Copy__Uint16ActionTime);

CheckStatus TMR_CheckStatusTimer0OVFSetCallBack(Void(*Copy_PTF)(Void));
CheckStatus TMR_CheckStatusTimer0CTCSetCallBack(Void (*Copy_PTF)(Void));



#endif