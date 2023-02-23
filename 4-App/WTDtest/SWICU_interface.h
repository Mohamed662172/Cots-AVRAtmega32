/*
 * SWICU_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef SWICU_INTERFACE_H_
#define SWICU_INTERFACE_H_

Void SWICU_VoidEnable(Void);
Void SWICU_VoidDisable(Void);
CheckStatus SWICU_CheckStatusGetTotalPeriod(_uint32 *Copy_Uint32TotalPeriod);
CheckStatus SWICU_CheckStatusGetDutyCycle(_uint32 *Copy_Uint32DutyCycle);
CheckStatus SWICU_CheckStatusGetOnPeriod(_uint32 *Copy_Uint32GetOnPeriod);
CheckStatus SWICU_CheckStatusGetOffPeriod(_uint32 *Copy_Uint32GetOffPeriod);
#endif /* SWICU_INTERFACE_H_ */
