/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/05/2020  ****************/
/*************** SWC      :    DIO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/
/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"
/* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/* HAL */

/* Defination Of Function  */
CheckStatus DIO__CheckStatusInit(Void)
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        
        /* intial direction */ 
        
        DDRA__UINT8_REG = CONC(DIO__UINT8_PA7_INITIAL_DIRECTION, DIO__UINT8_PA6_INITIAL_DIRECTION, DIO__UINT8_PA5_INITIAL_DIRECTION, DIO__UINT8_PA4_INITIAL_DIRECTION, DIO__UINT8_PA3_INITIAL_DIRECTION, DIO__UINT8_PA2_INITIAL_DIRECTION, DIO__UINT8_PA1_INITIAL_DIRECTION, DIO__UINT8_PA0_INITIAL_DIRECTION);
        DDRB__UINT8_REG = CONC(DIO__UINT8_PB7_INITIAL_DIRECTION, DIO__UINT8_PB6_INITIAL_DIRECTION, DIO__UINT8_PB5_INITIAL_DIRECTION, DIO__UINT8_PB4_INITIAL_DIRECTION, DIO__UINT8_PB3_INITIAL_DIRECTION, DIO__UINT8_PB2_INITIAL_DIRECTION, DIO__UINT8_PB1_INITIAL_DIRECTION, DIO__UINT8_PB0_INITIAL_DIRECTION);
        DDRC__UINT8_REG = CONC(DIO__UINT8_PC7_INITIAL_DIRECTION, DIO__UINT8_PC6_INITIAL_DIRECTION, DIO__UINT8_PC5_INITIAL_DIRECTION, DIO__UINT8_PC4_INITIAL_DIRECTION, DIO__UINT8_PC3_INITIAL_DIRECTION, DIO__UINT8_PC2_INITIAL_DIRECTION, DIO__UINT8_PC1_INITIAL_DIRECTION, DIO__UINT8_PC0_INITIAL_DIRECTION);
        DDRD__UINT8_REG = CONC(DIO__UINT8_PD7_INITIAL_DIRECTION, DIO__UINT8_PD6_INITIAL_DIRECTION, DIO__UINT8_PD5_INITIAL_DIRECTION, DIO__UINT8_PD4_INITIAL_DIRECTION, DIO__UINT8_PD3_INITIAL_DIRECTION, DIO__UINT8_PD2_INITIAL_DIRECTION, DIO__UINT8_PD1_INITIAL_DIRECTION, DIO__UINT8_PD0_INITIAL_DIRECTION);
        
        /* initial Value */
        
        PORTA__UINT8_REG = CONC(DIO__UINT8_PA7_INITIAL_VALUE, DIO__UINT8_PA6_INITIAL_VALUE, DIO__UINT8_PA5_INITIAL_VALUE, DIO__UINT8_PA4_INITIAL_VALUE, DIO__UINT8_PA3_INITIAL_VALUE, DIO__UINT8_PA2_INITIAL_VALUE, DIO__UINT8_PA1_INITIAL_VALUE, DIO__UINT8_PA0_INITIAL_VALUE);
        PORTB__UINT8_REG = CONC(DIO__UINT8_PB7_INITIAL_VALUE, DIO__UINT8_PB6_INITIAL_VALUE, DIO__UINT8_PB5_INITIAL_VALUE, DIO__UINT8_PB4_INITIAL_VALUE, DIO__UINT8_PB3_INITIAL_VALUE, DIO__UINT8_PB2_INITIAL_VALUE, DIO__UINT8_PB1_INITIAL_VALUE, DIO__UINT8_PB0_INITIAL_VALUE);
        PORTC__UINT8_REG = CONC(DIO__UINT8_PC7_INITIAL_VALUE, DIO__UINT8_PC6_INITIAL_VALUE, DIO__UINT8_PC5_INITIAL_VALUE, DIO__UINT8_PC4_INITIAL_VALUE, DIO__UINT8_PC3_INITIAL_VALUE, DIO__UINT8_PC2_INITIAL_VALUE, DIO__UINT8_PC1_INITIAL_VALUE, DIO__UINT8_PC0_INITIAL_VALUE);
        PORTD__UINT8_REG = CONC(DIO__UINT8_PD7_INITIAL_VALUE, DIO__UINT8_PD6_INITIAL_VALUE, DIO__UINT8_PD5_INITIAL_VALUE, DIO__UINT8_PD4_INITIAL_VALUE, DIO__UINT8_PD3_INITIAL_VALUE, DIO__UINT8_PD2_INITIAL_VALUE, DIO__UINT8_PD1_INITIAL_VALUE, DIO__UINT8_PD0_INITIAL_VALUE);


        return Local_CheckStatusReturnStatus;
}

CheckStatus DIO__CheckStatusSetPinDirection(_uint8 Copy__uint8PortId, _uint8 Copy__uint8PinId, _uint8 Copy__uint8PinDirection)
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        /*
        Check 1-Valid PORT Id
              2-Valid Pin  Id
              3-Valid Pin  Direction
        */
        if ((Copy__uint8PortId <= DIO__UINT8_PORTD) && (Copy__uint8PinId <= DIO__UINT8_PIN7) && ((Copy__uint8PinDirection == DIO__UINT8_OUTPUT) || (Copy__uint8PinDirection == DIO__UINT8_INPUT)))
        {
                switch (Copy__uint8PortId)
                {
                case DIO__UINT8_PORTA:
                        switch (Copy__uint8PinDirection)
                        {
                        case DIO__UINT8_OUTPUT:
                                SET_BIT(DDRA__UINT8_REG, Copy__uint8PinId);
                                break;

                        case DIO__UINT8_INPUT:
                                CLEAR_BIT(DDRA__UINT8_REG, Copy__uint8PinId);
                                break;

                        default:
                                /* = DO NOTHING */

                                break;
                        }
                        break;
                case DIO__UINT8_PORTB:
                        switch (Copy__uint8PinDirection)
                        {
                        case DIO__UINT8_OUTPUT:
                                SET_BIT(DDRB__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_INPUT:
                                CLEAR_BIT(DDRB__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                case DIO__UINT8_PORTC:
                        switch (Copy__uint8PinDirection)
                        {
                        case DIO__UINT8_OUTPUT:
                                SET_BIT(DDRC__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_INPUT:
                                CLEAR_BIT(DDRC__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                case DIO__UINT8_PORTD:
                        switch (Copy__uint8PinDirection)
                        {
                        case DIO__UINT8_OUTPUT:
                                SET_BIT(DDRD__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_INPUT:
                                CLEAR_BIT(DDRD__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                default:
                        /* DO NOTHING */
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
                return Local_CheckStatusReturnStatus;
        }
}

CheckStatus DIO__CheckStatusSetPinValue(_uint8 Copy__uint8PortId, _uint8 Copy__uint8PinId, _uint8 Copy__uint8PinValue)
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        /*
        Check 1-Valid PORT Id
              2-Valid Pin  Id
              3-Valid Pin  Value 
        */
        if ((Copy__uint8PortId <= DIO__UINT8_PORTD) && (Copy__uint8PinId <= DIO__UINT8_PIN7) && ((Copy__uint8PinValue == DIO__UINT8_HIGH) || (Copy__uint8PinValue == DIO__UINT8_LOW)))
        {
                switch (Copy__uint8PortId)
                {
                case DIO__UINT8_PORTA:
                        switch (Copy__uint8PinValue)
                        {
                        case DIO__UINT8_HIGH:
                                SET_BIT(PORTA__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_LOW:
                                CLEAR_BIT(PORTA__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                        break;
                case DIO__UINT8_PORTB:
                        switch (Copy__uint8PinValue)
                        {
                        case DIO__UINT8_HIGH:
                                SET_BIT(PORTB__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_LOW:
                                CLEAR_BIT(PORTB__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                case DIO__UINT8_PORTC:
                        switch (Copy__uint8PinValue)
                        {
                        case DIO__UINT8_HIGH:
                                SET_BIT(PORTC__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_LOW:
                                CLEAR_BIT(PORTC__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                case DIO__UINT8_PORTD:
                        switch (Copy__uint8PinValue)
                        {
                        case DIO__UINT8_HIGH:
                                SET_BIT(PORTD__UINT8_REG, Copy__uint8PinId);
                                break;
                        case DIO__UINT8_LOW:
                                CLEAR_BIT(PORTD__UINT8_REG, Copy__uint8PinId);
                                break;
                        default:
                                /* DO NOTHING */

                                break;
                        }
                default:
                        /* DO NOTHING */
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
                return Local_CheckStatusReturnStatus;
        }
}

CheckStatus DIO__CheckStatusGetPinValue(_uint8 Copy__uint8PortId, _uint8 Copy__uint8PinId, _uint8 *Copy_p_uint8ReturnPinValue)
{

        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        /*
        Check 1-Valid PORT Id
              2-Valid Pin  Id
              3-Valid Pointer != NULL
        */
        if ((Copy__uint8PortId <= DIO__UINT8_PORTD) && (Copy__uint8PinId <= DIO__UINT8_PIN7) && (Copy_p_uint8ReturnPinValue != NULL))
        {
                switch (Copy__uint8PortId)
                {
                case DIO__UINT8_PORTA:
                        if (GET_BIT(PINA__UINT8_REG, Copy__uint8PinId) == 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_LOW;
                        }
                        else if (GET_BIT(PINA__UINT8_REG, Copy__uint8PinId) != 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_HIGH;
                        }
                        else
                        {
                                /* DO NOTHING */
                        }

                        break;
                case DIO__UINT8_PORTB:
                        if (GET_BIT(PINB__UINT8_REG, Copy__uint8PinId) == 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_LOW;
                        }
                        else if (GET_BIT(PINB__UINT8_REG, Copy__uint8PinId) != 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_HIGH;
                        }
                        else
                        {
                                /* DO NOTHING */
                        }

                        break;

                case DIO__UINT8_PORTC:

                        if (GET_BIT(PINC__UINT8_REG, Copy__uint8PinId) == 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_LOW;
                        }
                        else if (GET_BIT(PINC__UINT8_REG, Copy__uint8PinId) != 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_HIGH;
                        }
                        else
                        {
                                /* DO NOTHING */
                        }

                        break;
                case DIO__UINT8_PORTD:
                        if (GET_BIT(PIND__UINT8_REG, Copy__uint8PinId) == 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_LOW;
                        }
                        else if (GET_BIT(PIND__UINT8_REG, Copy__uint8PinId) != 0)
                        {
                                *Copy_p_uint8ReturnPinValue = DIO__UINT8_HIGH;
                        }
                        else
                        {
                                /* DO NOTHING */
                        }

                        break;
                default:
                        /* DO NOTHING */
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
                return Local_CheckStatusReturnStatus;
        }
}

CheckStatus DIO__CheckStatusSetPortDirection(_uint8 Copy__uint8PortId, _uint8 Copy__uint8PortDirection)
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;

        /* 
        Check 1-Valid Port Id
              2-Valid PORT diraction 
        */

        if ((Copy__uint8PortId <= DIO__UINT8_PORTD) && ((Copy__uint8PortDirection == DIO__UINT8_OUTPUT) || (Copy__uint8PortDirection == DIO__UINT8_INPUT)))
        {
                switch (Copy__uint8PortId)
                {
                case DIO__UINT8_PORTA:
                        switch (Copy__uint8PortDirection)
                        {
                        case DIO__UINT8_INPUT:
                                PORTA__UINT8_REG = 0x00;
                                break;
                        case DIO__UINT8_OUTPUT:
                                PORTA__UINT8_REG = 0xFF;

                                break;
                        default:
                                /* DO  NOTHING */
                                break;
                        }
                        break;
                case DIO__UINT8_PORTB:
                        switch (Copy__uint8PortDirection)
                        {
                        case DIO__UINT8_INPUT:
                                PORTB__UINT8_REG = 0x00;
                                break;
                        case DIO__UINT8_OUTPUT:
                                PORTB__UINT8_REG = 0xFF;

                                break;
                        default:
                                /* DO  NOTHING */
                                break;
                        }

                        break;

                case DIO__UINT8_PORTC:
                        switch (Copy__uint8PortDirection)
                        {
                        case DIO__UINT8_INPUT:
                                PORTC__UINT8_REG = 0x00;
                                break;
                        case DIO__UINT8_OUTPUT:
                                PORTC__UINT8_REG = 0xFF;

                                break;
                        default:
                                /* DO  NOTHING */
                                break;
                        }

                        break;
                case DIO__UINT8_PORTD:
                        switch (Copy__uint8PortDirection)
                        {
                        case DIO__UINT8_INPUT:
                                PORTD__UINT8_REG = 0x00;
                                break;
                        case DIO__UINT8_OUTPUT:
                                PORTD__UINT8_REG = 0xFF;

                                break;
                        default:
                                /* DO  NOTHING */
                                break;
                        }
                        break;
                default:
                        /* DO NOTHING */
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
                return Local_CheckStatusReturnStatus;
        }
}

CheckStatus DIO__CheckStatusSetPortValue(_uint8 Copy__uint8PortId, _uint8 Copy__uint8PortValue)
{

        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        /*
        Check 1-Valid PORT Id
               
        */
        if (Copy__uint8PortId <= DIO__UINT8_PORTD)
        {
                switch (Copy__uint8PortId)
                {
                case DIO__UINT8_PORTA:
                        PORTA__UINT8_REG = Copy__uint8PortValue;
                        break;
                case DIO__UINT8_PORTB:
                        PORTB__UINT8_REG = Copy__uint8PortValue;
                        break;
                case DIO__UINT8_PORTC:
                        PORTC__UINT8_REG = Copy__uint8PortValue;
                        break;
                case DIO__UINT8_PORTD:
                        PORTD__UINT8_REG = Copy__uint8PortValue;
                        break;
                default:
                        /* DO NOTHING */
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
                return Local_CheckStatusReturnStatus;
        }
}

CheckStatus DIO__CheckStatusGetPortValue(_uint8 Copy__uint8PortId, _uint8 *Copy_p_uint8ReturnPortValue)
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        /*
        Check 1-Valid Pointer != NULL
               
        */
        if (Copy_p_uint8ReturnPortValue != NULL)
        {
                switch (Copy__uint8PortId)
                {
                case DIO__UINT8_PORTA:
                        *Copy_p_uint8ReturnPortValue = PINA__UINT8_REG;
                        break;
                case DIO__UINT8_PORTB:
                        *Copy_p_uint8ReturnPortValue = PINB__UINT8_REG;

                        break;
                case DIO__UINT8_PORTC:
                        *Copy_p_uint8ReturnPortValue = PINC__UINT8_REG;
                        break;
                case DIO__UINT8_PORTD:
                        *Copy_p_uint8ReturnPortValue = PIND__UINT8_REG;
                        break;
                default:
                        /* DO NOTHING */
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
                return Local_CheckStatusReturnStatus;
        }
}
