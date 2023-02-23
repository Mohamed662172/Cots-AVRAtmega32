/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/08/2020  ****************/
/*************** SWC      :    LCD       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#define  LCD__UINT8_LOCATION_NUMBER39   39
/* Defination Of Function  */
void LCD_CheckStatusInit(Void)
{
        //CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        _delay_ms(35);
        /* Function Set Cmnd 0b00111000*/

        LCD_CheckStatusSendCmnd(0b00111000);
        _delay_us(40);
        LCD_CheckStatusSendCmnd(0b00001111);
        _delay_us(40);
        LCD_CheckStatusSendCmnd(0b00000001);
        _delay_ms(2);
        LCD_CheckStatusSendCmnd(0b00000110);

        //return Local_CheckStausReturnValue;
}
void LCD_CheckStatusSendCmnd(_uint8 Copy__Uint8Cmnd)
{
//        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        /*
         1-Rs  =  0
         2-R/W =  0
         3-Send Cmnd byte  to the Data Pins of Lcd
         4-Pluse of Enable E = 1 ,E = 0
        */
        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_LOW);

        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

        DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, Copy__Uint8Cmnd);

        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
        _delay_us(1);
        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
        _delay_us(1);
//        return Local_CheckStausReturnValue;
}
void LCD_CheckStatusSendChar(_uint8 Copy__Uint8Char)
{
//        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        /*
         1-Rs  =  1
         2-R/W =  0
         3-Send Cmnd byte  to the Data Pins of Lcd
         4-Pluse of Enable E = 1 ,E = 0
        */
        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_HIGH);

        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

        DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, Copy__Uint8Char);

        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
        _delay_ms(50);
        DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
        _delay_ms(50);
//        return Local_CheckStausReturnValue;
}

CheckStatus LCD_CheckStatusWriteString(_uint8 *Copy_p__Uint8String)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        _uint8 Local__Uint8Index = DIO__UINT8_LOW;

        if (Copy_p__Uint8String != NULL)
        {
                for (Local__Uint8Index = DIO__UINT8_LOW; *(Copy_p__Uint8String + Local__Uint8Index) != '\0'; ++Local__Uint8Index)
                {
                        LCD_CheckStatusSendChar(*(Copy_p__Uint8String + Local__Uint8Index));
                }
                return Local_CheckStausReturnValue;
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
                return Local_CheckStausReturnValue;
        }
}

CheckStatus LCD_CheckStatusGoToXY(_uint8 Copy__Uint8LineNumber, _uint8 Copy__Uint8LocationNumber)
{

        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;

        if ((Copy__Uint8LineNumber <= LCD__UINT8_LINE2) && (Copy__Uint8LocationNumber <= LCD__UINT8_LOCATION_NUMBER39))
        {
                
                switch (Copy__Uint8LineNumber)
                {
                case LCD__UINT8_LINE1:
                        LCD_CheckStatusSendCmnd(0x80 + Copy__Uint8LocationNumber); //base +offsite
                        break;
                case LCD__UINT8_LINE2:
                        LCD_CheckStatusSendCmnd(0xC0 + Copy__Uint8LocationNumber);
                        break;
                default:
                        break;
                }
                return Local_CheckStausReturnValue;
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
                return Local_CheckStausReturnValue;
        }
}
