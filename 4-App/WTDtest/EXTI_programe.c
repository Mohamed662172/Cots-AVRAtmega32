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

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

// ARR OF 3 POINTER TO Function

static Void (*EXTI_AP_VoidIsr[3])(Void) = {NULL,NULL,NULL};

/* ISR Function prototype */
/* EXTINT0 ISR */
void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
        if (EXTI_AP_VoidIsr[INT0] != NULL)
        {
                EXTI_AP_VoidIsr[INT0]();
        }
        else
        {
                /* DO NOTHING */
        }
        
}
/* EXTINT1 ISR */

void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
        if (EXTI_AP_VoidIsr[INT1] != NULL)
        {
                EXTI_AP_VoidIsr[INT1]();
        }
        else
        {
                /* DO NOTHING */
        }
        
}
/* EXTINT2 ISR */

void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
        if (EXTI_AP_VoidIsr[INT2] != NULL)
        {
                EXTI_AP_VoidIsr[INT2]();
        }
        else
        {
                /* DO NOTHING */
        }
        
}

/* SET CALL BACK FUNCTION  */

CheckStatus EXTI_CheckStatusSetCallBackFunc(Void (*Copy_VoidPointerToFunction)(Void), _uint8 Copy__Uint8ExtiIndex)
{
        CheckStatus Local_CheckStatusReturnValue = CHECK_SUCCESS;

        if (Copy__Uint8ExtiIndex <= INT2 && Copy_VoidPointerToFunction != NULL)
        {
                EXTI_AP_VoidIsr[Copy__Uint8ExtiIndex] = Copy_VoidPointerToFunction;
        }
        else
        {
                Local_CheckStatusReturnValue = CHECK_FAIL;
        }

        return Local_CheckStatusReturnValue;
}

CheckStatus EXIT_CheckStatusExtIntEnable(_uint8 Copy__Uint8ExtIntId, _uint8 Copy__Uint8ExtIntEdge)
{
        CheckStatus Local_CheckStatusReturnValue = CHECK_SUCCESS;
        if (Copy__Uint8ExtIntId <= INT2 && (Copy__Uint8ExtIntEdge <= EXIT_UINT8_LOGICAL_CHANGE_EDGE && Copy__Uint8ExtIntEdge >= EXIT_UINT8_FALLING_EDGE))
        {
                switch (Copy__Uint8ExtIntId)
                {
                case INT0:

                        switch (Copy__Uint8ExtIntEdge)
                        {
                        case EXIT_UINT8_LOW_LEVEL_EDGE:
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);

                                break;
                        case EXIT_UINT8_LOGICAL_CHANGE_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);
                                break;
                        case EXIT_UINT8_FALLING_EDGE:
                                /* code */
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);
                                break;
                        case EXIT_UINT8_RIASING_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);
                                break;
                        default:
                                break;
                        }
                        SET_BIT(EXTI__UINT8_GICR_REG, GICR_INT0);
                        break;
                case INT1:
                        switch (Copy__Uint8ExtIntEdge)
                        {
                        case EXIT_UINT8_LOW_LEVEL_EDGE:
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);

                                break;
                        case EXIT_UINT8_LOGICAL_CHANGE_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);
                                break;
                        case EXIT_UINT8_FALLING_EDGE:
                                /* code */
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);
                                break;
                        case EXIT_UINT8_RIASING_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);
                                break;
                        default:
                                break;
                        }

                        SET_BIT(EXTI__UINT8_GICR_REG, GICR_INT1);

                        break;
                case INT2:
                        /* code */
                        switch (Copy__Uint8ExtIntEdge)
                        {
                        case EXIT_UINT8_FALLING_EDGE:
                                SET_BIT(EXTI__UINT8_MCUCSR_REG, MCUCSR_ISC2);
                                break;
                        case EXIT_UINT8_RIASING_EDGE:
                                /* code */
                                CLEAR_BIT(EXTI__UINT8_MCUCSR_REG, MCUCSR_ISC2);
                                break;
                        default:
                                break;
                        }
                        SET_BIT(EXTI__UINT8_GICR_REG, GICR_INT2);

                        break;
                default:
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnValue = CHECK_FAIL;
        }

        return Local_CheckStatusReturnValue;
}

CheckStatus EXTI_CheckStatusDisable(_uint8 Copy__Uint8ExtIntId)
{
        CheckStatus Local_CheckStatusReturnValue = CHECK_SUCCESS;
        switch (Copy__Uint8ExtIntId)
        {
        case INT0:
                CLEAR_BIT(EXTI__UINT8_GICR_REG, GICR_INT0);
                break;
        case INT1:
                CLEAR_BIT(EXTI__UINT8_GICR_REG, GICR_INT1);
                break;
        case INT2:
                CLEAR_BIT(EXTI__UINT8_GICR_REG, GICR_INT2);
                break;
        default:
                Local_CheckStatusReturnValue = CHECK_FAIL;
                break;
        }
        return Local_CheckStatusReturnValue;
}
