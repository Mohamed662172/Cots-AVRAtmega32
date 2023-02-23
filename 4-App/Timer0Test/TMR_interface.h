/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  26/05/2020  ****************/
/*************** SWC      :   TMR0       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

CheckStatus TMR_CheckSatusInit( _uint16 Copy__Uint16ActionTime);

CheckStatus TMR_CheckStatusTimer0OVFSetCallBack(Void(*Copy_PTF)(Void));
CheckStatus TMR_CheckStatusTimer0CTCSetCallBack(Void (*Copy_PTF)(Void));
Void TMR_CHANGE_OCRC0(_uint8 Copy__Uint8OCR0Value);
Void TMR_VoidTimer1INIT(Void);
Void TMR_VOidTimer1SEtCompareMatchValue(_uint16 copy_value);

#endif
