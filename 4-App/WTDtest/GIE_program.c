/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  17/09/2020  ****************/                                                                          
/*************** SWC      :   EXTI       ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/ 

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL LAYER*/
#include"GIE_interface.h"
#include"GIE_private.h"
#include"GIE_config.h"


Void  GIE_VoidEnable(Void) 
{
         SET_BIT(GIE_UINT8_STATUS_REG,GIE_GLOBAL_INT_STATE);
}

Void  GIE_VoidDisable(Void)
{
        CLEAR_BIT(GIE_UINT8_STATUS_REG,GIE_GLOBAL_INT_STATE);
}
