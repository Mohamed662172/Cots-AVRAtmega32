/*
 * SWICU_programe.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
/* LIB_LAYER*/
#include "Std_Types.h"
#include "Bit_Math.h"
/* MCAL_LAYER */
#include "EXTI_interface.h"
#include "TMR_interface.h"
/* HAL LAYER*/
#include "SWICU_interface.h"
#include "SWICU_private.h"
#include "SWICU_config.h"

Void SWICU_VoidEnable(Void)
{



}
Void SWICU_VoidDisable(Void);
CheckStatus SWICU_CheckStatusGetTotalPeriod(_uint32 *Copy_Uint32TotalPeriod);
CheckStatus SWICU_CheckStatusGetDutyCycle(_uint32 *Copy_Uint32DutyCycle);
CheckStatus SWICU_CheckStatusGetOnPeriod(_uint32 *Copy_Uint32GetOnPeriod);
CheckStatus SWICU_CheckStatusGetOffPeriod(_uint32 *Copy_Uint32GetOffPeriod);


static Void App_voidICUInterrupt(Void)
{
    _uint16 Local_Uint16TimerValue;
    static _uint8 Local_Uint8Flag = 0 ;
    static _uint16 Local_Uint16TempTimerValue = 0 ;





}
