
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
/* EXTEXTI_UINT8_INT0 ISR */
void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
        if (EXTI_AP_VoidIsr[EXTI_UINT8_INT0] != NULL)
        {
                EXTI_AP_VoidIsr[EXTI_UINT8_INT0]();
        }
        else
        {
                /* DO NOTHING */
        }
        
}
/* EXTEXTI_UINT8_INT1 ISR */

void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
        if (EXTI_AP_VoidIsr[EXTI_UINT8_INT1] != NULL)
        {
                EXTI_AP_VoidIsr[EXTI_UINT8_INT1]();
        }
        else
        {
                /* DO NOTHING */
        }
        
}
/* EXTEXTI_UINT8_INT2 ISR */

void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
        if (EXTI_AP_VoidIsr[EXTI_UINT8_INT2] != NULL)
        {
                EXTI_AP_VoidIsr[EXTI_UINT8_INT2]();
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

        if (Copy__Uint8ExtiIndex <= EXTI_UINT8_INT2 && Copy_VoidPointerToFunction != NULL)
        {
                EXTI_AP_VoidIsr[Copy__Uint8ExtiIndex] = Copy_VoidPointerToFunction;
        }
        else
        {
                Local_CheckStatusReturnValue = CHECK_FAIL;
        }

        return Local_CheckStatusReturnValue;
}

CheckStatus EXTI_CheckStatusExtIntEnable(_uint8 Copy__Uint8ExtIntId, _uint8 Copy__Uint8ExtIntEdge)
{
        CheckStatus Local_CheckStatusReturnValue = CHECK_SUCCESS;
        if (Copy__Uint8ExtIntId <= EXTI_UINT8_INT2 && (Copy__Uint8ExtIntEdge <= EXTI_UINT8_LOGICAL_CHANGE_EDGE && Copy__Uint8ExtIntEdge >= EXTI_UINT8_FALLING_EDGE))
        {
                switch (Copy__Uint8ExtIntId)
                {
                case EXTI_UINT8_INT0:

                        switch (Copy__Uint8ExtIntEdge)
                        {
                        case EXTI_UINT8_LOW_LEVEL_EDGE:
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);

                                break;
                        case EXTI_UINT8_LOGICAL_CHANGE_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);
                                break;
                        case EXTI_UINT8_FALLING_EDGE:
                                /* code */
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);
                                break;
                        case EXTI_UINT8_RIASING_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC00);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC01);
                                break;
                        default:
                                break;
                        }
                        SET_BIT(EXTI__UINT8_GICR_REG, GICR_EXTI_UINT8_INT0);
                        break;
                case EXTI_UINT8_INT1:
                        switch (Copy__Uint8ExtIntEdge)
                        {
                        case EXTI_UINT8_LOW_LEVEL_EDGE:
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);

                                break;
                        case EXTI_UINT8_LOGICAL_CHANGE_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);
                                break;
                        case EXTI_UINT8_FALLING_EDGE:
                                /* code */
                                CLEAR_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);
                                break;
                        case EXTI_UINT8_RIASING_EDGE:
                                /* code */
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC10);
                                SET_BIT(EXTI__UINT8_MCUCR_REG, MCUCR_ISC11);
                                break;
                        default:
                                break;
                        }

                        SET_BIT(EXTI__UINT8_GICR_REG, GICR_EXTI_UINT8_INT1);

                        break;
                case EXTI_UINT8_INT2:
                        /* code */
                        switch (Copy__Uint8ExtIntEdge)
                        {
                        case EXTI_UINT8_FALLING_EDGE:
                                SET_BIT(EXTI__UINT8_MCUCSR_REG, MCUCSR_ISC2);
                                break;
                        case EXTI_UINT8_RIASING_EDGE:
                                /* code */
                                CLEAR_BIT(EXTI__UINT8_MCUCSR_REG, MCUCSR_ISC2);
                                break;
                        default:
                                break;
                        }
                        SET_BIT(EXTI__UINT8_GICR_REG, GICR_EXTI_UINT8_INT2);

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
        CheckStatus Local_CheckStatusReturnValue = CHECK_SUCCES;
        switch (Copy__Uint8ExtIntId)
        {
        case EXTI_UINT8_INT0:
                CLEAR_BIT(EXTI__UINT8_GICR_REG, GICR_EXTI_UINT8_INT0);
                break;
        case EXTI_UINT8_INT1:
                CLEAR_BIT(EXTI__UINT8_GICR_REG, GICR_EXTI_UINT8_INT1);
                break;
        case EXTI_UINT8_INT2:
                CLEAR_BIT(EXTI__UINT8_GICR_REG, GICR_EXTI_UINT8_INT2);
                break;
        default:
                Local_CheckStatusReturnValue = CHECK_FAIL;
                break;
        }
        return Local_CheckStatusReturnValue;
}
