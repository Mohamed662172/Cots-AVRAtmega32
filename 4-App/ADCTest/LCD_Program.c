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
#define LCD__UINT8_LOCATION_NUMBER39 39
#define LCD__UINT8_CG_RAMLOCATION7 7

static _uint8 LCD_A_UINT8CHAR1[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR1_VALUE;
static _uint8 LCD_A_UINT8CHAR2[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR2_VALUE;
static _uint8 LCD_A_UINT8CHAR3[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR3_VALUE;
static _uint8 LCD_A_UINT8CHAR4[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR4_VALUE;
static _uint8 LCD_A_UINT8CHAR5[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR5_VALUE;
static _uint8 LCD_A_UINT8CHAR6[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR6_VALUE;
static _uint8 LCD_A_UINT8CHAR7[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR7_VALUE;
static _uint8 LCD_A_UINT8CHAR8[8] = LCD_ARRAY_UINT8_SPECIAL_CHAR8_VALUE;

static _uint8 *LCD_A_UINT8SPECIALCHAR[8] = {LCD_A_UINT8CHAR1,
                                     LCD_A_UINT8CHAR2,
                                     LCD_A_UINT8CHAR3,
                                     LCD_A_UINT8CHAR4,
                                     LCD_A_UINT8CHAR5,
                                     LCD_A_UINT8CHAR6,
                                     LCD_A_UINT8CHAR7,
                                     LCD_A_UINT8CHAR8};
/* Defination Of Function  */
Void LCD_VoidInit(Void)
{

        _delay_ms(35);
        /* Function Set Cmnd 0b00111000*/

        LCD_CheckStatusSendCmnd(0b00111000);
        _delay_us(40);
        LCD_CheckStatusSendCmnd(0b00001111);
        _delay_us(40);
        LCD_CheckStatusSendCmnd(0b00000001);
        _delay_ms(2);
        LCD_CheckStatusSendCmnd(0b00000110);
}
CheckStatus LCD_CheckStatusSendCmnd(_uint8 Copy__Uint8Cmnd)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        /*
         1-RS  =  0
         2-R/W =  0
         3-Send CMND byte  to the Data Pins of LCD
         4-PULSE of Enable E = 1 ,E = 0
        */
        if (Copy__Uint8Cmnd <= 255)
        {
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, Copy__Uint8Cmnd);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
                _delay_us(1);
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}
CheckStatus LCD_CheckStatusSendChar(_uint8 Copy__Uint8Char)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        /*
         1-RS  =  0
         2-R/W =  0
         3-Send CMND byte  to the Data Pins of LCD
         4-PULSE of Enable E = 1 ,E = 0
        */
        if (Copy__Uint8Char <= 255)
        {
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_HIGH);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, Copy__Uint8Char);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
                _delay_us(1);
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}

CheckStatus LCD_CheckStatusWriteString(_uint8 *Copy_p__Uint8String)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        _uint8 Local__Uint8Index = DIO__UINT8_LOW;

        if (Copy_p__Uint8String != NULL)
        {
                for (Local__Uint8Index = DIO__UINT8_LOW; *(Copy_p__Uint8String + Local__Uint8Index) != '\0'; ++Local__Uint8Index)
                {
                        LCD_CheckStatusSendChar4bit(*(Copy_p__Uint8String + Local__Uint8Index));
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

        if ((Copy__Uint8LineNumber <= 1) && (Copy__Uint8LocationNumber <= 39))
        {

                switch (Copy__Uint8LineNumber)
                {
                case LCD__UINT8_LINE1:
                        LCD_CheckStatusSendCmnd4bit(0x80 + Copy__Uint8LocationNumber); //BASE +OFFSET
                        break;
                case LCD__UINT8_LINE2:
                        LCD_CheckStatusSendCmnd4bit(0xc0 + Copy__Uint8LocationNumber);
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

Void LCD_VoidClearDisplay(Void)
{
        LCD_CheckStatusSendCmnd4bit(0x01);
        _delay_ms(2);
}
CheckStatus LCD_CheckStatusSendNumber(_uint32 Copy__Uint32Number)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;

        _uint8 Local__Uint8Remendier = 0x00;
        _uint8 Local__Uint8Counter = 0x00;
        _uint32 Local__Uint32Temporary = 0;
        if (Copy__Uint32Number <= 4294967296)
        {
                while (Copy__Uint32Number != 0)
                {
                        Local__Uint32Temporary = Local__Uint32Temporary * 0x0A;
                        Local__Uint32Temporary = Local__Uint32Temporary + Copy__Uint32Number % 0x0A;
                        Copy__Uint32Number = Copy__Uint32Number / 0x0A;
                }

                for (Local__Uint8Counter = 0; Local__Uint32Temporary != 0; ++Local__Uint8Counter)
                {
                        Local__Uint8Remendier = Local__Uint32Temporary % 0x0A;
                        Local__Uint32Temporary = Local__Uint32Temporary / 0x0A;
                        switch (Local__Uint8Remendier)
                        {
                        case 0:
                                LCD_CheckStatusSendChar4bit('0');
                                break;
                        case 1:
                                LCD_CheckStatusSendChar4bit('1');
                                break;
                        case 2:
                                LCD_CheckStatusSendChar4bit('2');
                                break;
                        case 3:
                                LCD_CheckStatusSendChar4bit('3');
                                break;
                        case 4:
                                LCD_CheckStatusSendChar4bit('4');
                                break;
                        case 5:
                                LCD_CheckStatusSendChar4bit('5');
                                break;
                        case 6:
                                LCD_CheckStatusSendChar4bit('6');
                                break;
                        case 7:
                                LCD_CheckStatusSendChar4bit('7');
                                break;
                        case 8:
                                LCD_CheckStatusSendChar4bit('8');
                                break;
                        case 9:
                                LCD_CheckStatusSendChar4bit('9');
                                break;
                        default:
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

CheckStatus LCD_CheckStatusSpecialChar(_uint8 Copy__Uint8CGRamLocation, _uint8 Copy__Uint8LCDLine, _uint8 Copy__Uint8DDRamLocation)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;

        _uint8 Local__Uint8CounterJ = 0x00;
        if ((Copy__Uint8CGRamLocation <= LCD__UINT8_CG_RAMLOCATION7) && (Copy__Uint8DDRamLocation <= LCD__UINT8_LOCATION_NUMBER39))
        {

                switch (Copy__Uint8CGRamLocation)
                {

                case 1:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE0);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[0][Local__Uint8CounterJ]);
                        }
                        break;
                case 2:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE1);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[1][Local__Uint8CounterJ]);
                        }
                        break;
                case 3:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE2);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[2][Local__Uint8CounterJ]);
                        }
                        break;
                case 4:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE3);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[3][Local__Uint8CounterJ]);
                        }
                        break;
                case 5:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE4);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[4][Local__Uint8CounterJ]);
                        }
                        break;
                case 6:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE5);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[5][Local__Uint8CounterJ]);
                        }
                        break;
                case 7:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE6);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[6][Local__Uint8CounterJ]);
                        }
                        break;
                case 8:
                        LCD_CheckStatusSendCmnd4bit(LCD__UINT8_CGRAM_BYTE7);
                        for (Local__Uint8CounterJ = 0; Local__Uint8CounterJ < 8; ++Local__Uint8CounterJ)
                        {
                                LCD_CheckStatusSendChar4bit(LCD_A_UINT8SPECIALCHAR[8][Local__Uint8CounterJ]);
                        }
                        break;
                default:
                        break;
                }

                LCD_CheckStatusGoToXY(Copy__Uint8LCDLine, Copy__Uint8DDRamLocation);
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}
Void LCD_VoidShiftRight(_uint8 Copy__Uint8PositionValue, _uint32 Copy__Uint32DelayValue)
{
        _uint8 Local__Uint8Counter;
        for (Local__Uint8Counter = 0; Local__Uint8Counter < Copy__Uint8PositionValue; ++Local__Uint8Counter)
        {
                LCD_CheckStatusSendCmnd4bit(0b00011100);
                _delay_ms(Copy__Uint32DelayValue);
        }
}
CheckStatus LCD_CheckStatusShiftRightOrLeft(_uint32 Copy__Uint32DelayValue)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        if (LCD__UINT8_SHIFT_ACTIVATE == 1 || LCD__UINT8_SHIFT_ACTIVATE == 0)
        {

                if (LCD__UINT8_SHIFT_ACTIVATE == 0)
                {
                        //right
                        LCD_CheckStatusSendCmnd4bit(0b00011100);
                        _delay_ms(Copy__Uint32DelayValue);
                }
                else if (LCD__UINT8_SHIFT_ACTIVATE == 1)
                {
                        //Left
                        LCD_CheckStatusSendCmnd4bit(0b00011000);
                        _delay_ms(Copy__Uint32DelayValue);
                }

        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}
Void LCD_VoidShiftLeft(_uint8 Copy__Uint8PositionValue, _uint32 Copy__Uint32DelayValue)
{
        _uint8 Local__Uint8Counter;
        for (Local__Uint8Counter = 0; Local__Uint8Counter < Copy__Uint8PositionValue; ++Local__Uint8Counter)
        {
                LCD_CheckStatusSendCmnd4bit(0b00011000);
                _delay_ms(Copy__Uint32DelayValue);
        }
}
CheckStatus LCD_CheckStatusDisplaySpecialChar(_uint8 Copy__Uint8Char)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        if (Copy__Uint8Char <= 8)
        {
                switch (Copy__Uint8Char)
                {

                case 1:
                        LCD_CheckStatusSendChar4bit(0);
                        break;
                case 2:
                        LCD_CheckStatusSendChar4bit(1);
                        break;
                case 3:
                        LCD_CheckStatusSendChar4bit(2);

                        break;
                case 4:
                        LCD_CheckStatusSendChar4bit(3);
                        break;
                case 5:
                        LCD_CheckStatusSendChar4bit(4);
                        break;
                case 6:
                        LCD_CheckStatusSendChar4bit(5);
                        break;
                case 7:
                        LCD_CheckStatusSendChar4bit(6);
                        break;
                case 8:
                        LCD_CheckStatusSendChar4bit(7);
                        break;
                default:
                        break;
                }
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}
Void LCD_VoidInit4bit(Void)
{
        _delay_ms(35);
        LCD_CheckStatusSendCmnd(0b00100000);
        LCD_CheckStatusSendCmnd(0b00100000);
        LCD_CheckStatusSendCmnd(0b11000000);
        _delay_us(40);
        LCD_CheckStatusSendCmnd(0b00000000);
        LCD_CheckStatusSendCmnd(0b11110000);
        _delay_us(40);
        LCD_CheckStatusSendCmnd(0b00000000);
        LCD_CheckStatusSendCmnd(0b00010000);
        _delay_ms(2);
        LCD_CheckStatusSendCmnd(0b00000000);
        LCD_CheckStatusSendCmnd(0b01100000);
}

CheckStatus LCD_CheckStatusSendChar4bit(_uint8 Copy__Uint8Char)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        /*
	         1-RS  =  1
	         2-R/W =  0
	         3-Send CHAR byte  to the Data Pins of LCD
	         4-PULSE of Enable E = 1 ,E = 0
	        */
        if (Copy__Uint8Char <= 255)
        {
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_HIGH);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, Copy__Uint8Char & LCD__UINT8_DATA_PINS);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
                _delay_us(1);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_HIGH);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, (Copy__Uint8Char << 4) & LCD__UINT8_DATA_PINS);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
                _delay_us(1);
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}
CheckStatus LCD_CheckStatusSendCmnd4bit(_uint8 Copy__Uint8Cmnd)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        /*
         1-RS  =  0
         2-R/W =  0
         3-Send CMND byte  to the Data Pins of LCD
         4-PULSE of Enable E = 1 ,E = 0
        */
        if (Copy__Uint8Cmnd <= 255)
        {
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT,( Copy__Uint8Cmnd & LCD__UINT8_DATA_PINS));

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RS_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_RW_PIN, DIO__UINT8_LOW);

                DIO__CheckStatusSetPortValue(LCD__UINT8_DATA_PORT, ((Copy__Uint8Cmnd << 4) & LCD__UINT8_DATA_PINS));

                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_HIGH);
                _delay_us(1);
                DIO__CheckStatusSetPinValue(LCD__UINT8_CONTROL_PORT, LCD__UINT8_E_PIN, DIO__UINT8_LOW);
                _delay_us(1);
        }
        else
        {
                Local_CheckStausReturnValue = CHECK_FAIL;
        }
        return Local_CheckStausReturnValue;
}
