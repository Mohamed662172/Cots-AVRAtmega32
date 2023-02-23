/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     : 28/08/2020   ****************/
/*************** SWC      :   KEYPAD     ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/
/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"
#define F_CPU 8000000U
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPAD_interface.h"
#include "KPAD_private.h"
#include "KPAD_config.h"

_uint8 KPAD_A_UINT8ROWSPINS[4] = {KPAD__UINT8_ROW1,KPAD__UINT8_ROW2,KPAD__UINT8_ROW3,KPAD__UINT8_ROW4};
_uint8 KPAD_A_UINT8COLSPINS[4] = {KPAD__UINT8_COL1,KPAD__UINT8_COL2,KPAD__UINT8_COL3,KPAD__UINT8_COL4};
_uint8 KPAD_A_UINT8KEYS[4][4] = KPAD_A_UINT8VALUE  ;

CheckStatus KPAD_CheckStatusGetKey(_uint8 *Copy_P_Uint8ReturnValue)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;

        _uint8 Local__Uint8RowsCounter;
        _uint8 Local__Uint8ColsCounter;
        _uint8 Local__Uint8ReturnPinValue;
        _uint8 Local__Uint8Flag = 0;

        if (Copy_P_Uint8ReturnValue != NULL)
        {  
               *Copy_P_Uint8ReturnValue= KPAD__UINT8_KEY_NOT_PRESSED;     
                for (Local__Uint8RowsCounter = 0; Local__Uint8RowsCounter <= 3; ++Local__Uint8RowsCounter)
                {
                        DIO__CheckStatusSetPinValue(KPAD__UINT8_PORT, KPAD_A_UINT8ROWSPINS[Local__Uint8RowsCounter], DIO__UINT8_LOW);
                        for (Local__Uint8ColsCounter = 0; Local__Uint8ColsCounter <= 3; ++Local__Uint8ColsCounter)
                        {

                                DIO__CheckStatusGetPinValue(KPAD__UINT8_PORT, KPAD_A_UINT8COLSPINS[Local__Uint8ColsCounter], &Local__Uint8ReturnPinValue);

                                /*Check if switch is pressed */
                                if (Local__Uint8ReturnPinValue == DIO__UINT8_LOW)
                                {
                                        /* debouncing */
                                        _delay_ms(20);
                                        while (Local__Uint8ReturnPinValue == DIO__UINT8_LOW)
                                        {
                                                DIO__CheckStatusGetPinValue(KPAD__UINT8_PORT, KPAD_A_UINT8COLSPINS[Local__Uint8ColsCounter], &Local__Uint8ReturnPinValue);
                                        }
                                        *Copy_P_Uint8ReturnValue = KPAD_A_UINT8KEYS[Local__Uint8RowsCounter][Local__Uint8ColsCounter];
                                        Local__Uint8Flag = 1;
                                        break;
                                }
                        }
                        DIO__CheckStatusSetPinValue(KPAD__UINT8_PORT, KPAD_A_UINT8ROWSPINS[Local__Uint8RowsCounter], DIO__UINT8_LOW);
                        if (Local__Uint8Flag == 1)
                        {

                                break;
                        }
                }
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }

        return Local_CheckStausReturnValue;
}
