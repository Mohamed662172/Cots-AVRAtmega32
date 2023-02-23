/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  26/05/2020  ****************/
/*************** SWC      :   TMR0       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL */
#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_config.h"

/* global pointer to function*/
static Void (*TMR_PTF_VoidTIMEROVF)(Void);
static Void (*TMR_PTF_VoidTIMERCTC)(Void);

static _float32 Local__Float32NumberOfOVF = 0.0;
static _uint8 Local__Uint8_PrloadNum = 0;

CheckStatus TMR_CheckSatusInit(_uint16 Copy__Uint16ActionTime)
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        _uint32 Local__Uint32FreqTime = 0x00;
        _uint32 Local_Uint32TimeOVF = 0x00;

        _float32 Local__Float32Fraction = 0.0;

        if (Copy__Uint16ActionTime <= 65536)
        {
                /* Select mode of timer */
                switch (TMR__UINT8_MODE_TIMER)
                {
                case TMR_IN_NORMAL_MODE:
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM00);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM01);
                        switch (TMR__UINT8_COMPARE_MATCH_OUTPUT)
                        {
                        case TMR_CMOMODE_OC0_DISCONNECTED:
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_TOGGLE:
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_SET:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_CLEAR:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        default:
                                break;
                        }
                        /* SET PRELODE VALUE */
                        Local__Uint32FreqTime = (_uint32)(TMR__UINT32_F_CPU / 8);
                        Local_Uint32TimeOVF = (_uint32)((1000000UL / (_uint32)Local__Uint32FreqTime) * 256);
                        Local__Float32NumberOfOVF = (_float32)(((_float32)Copy__Uint16ActionTime * 1000000.00) / (_float32)Local_Uint32TimeOVF);
                        Local__Float32Fraction = (_float32)(Local__Float32NumberOfOVF - (_uint32)Local__Float32NumberOfOVF);
                        Local__Uint8_PrloadNum = (_uint8)(256 - 256.0 * Local__Float32Fraction);
                        TMR__UINT8_TCNT0_REG = Local__Uint8_PrloadNum;
                        /* ENABLE INTERRUPT OVERFLOW */
                        SET_BIT(TMR__UINT8_TIMSK_REG, TMR_TIMSK_TOIF0);
                        break;
                case TMR_IN_PWM_MODE:
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM00);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM01);
                        switch (TMR__UINT8_COMPARE_MATCH_OUTPUT_PHASE_CORRECT)
                        {
                        case TMR_CMOMODE_OC0_DISCONNECTED:
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_SET_PHASE_CORRECT:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_CLEAR_PHASE_CORRECT:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        default:
                                break;
                        }
                        break;
                case TMR_IN_CTC_MODE:
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM00);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM01);
                        switch (TMR__UINT8_COMPARE_MATCH_OUTPUT)
                        {
                        case TMR_CMOMODE_OC0_DISCONNECTED:
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_TOGGLE:
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_SET:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_CLEAR:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        default:
                                break;
                        }
                        TMR__UINT8_OCRO_REG = 99;
                        SET_BIT(TMR__UINT8_TIMSK_REG, TMR_TIMSK_OCIE0);
                        break;
                case TMR_IN_FAST_PWM_MODE:
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM00);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_WGM01);
                        switch (TMR__UINT8_COMPARE_MATCH_OUTPUT_FAST_PWM)
                        {
                        case TMR_CMOMODE_OC0_DISCONNECTED:
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_SET_FAST_PWM:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        case TMR_CMOMODE_OC0_CLEAR_FAST_PWM:
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM01);
                                SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_COM00);
                                break;
                        default:
                                break;
                        }
                        break;
                default:
                        break;
                }

                switch (TMR__UINT8_SELECT_TIMER)
                {
                case TMR_NO_CLK_SOURCE:
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_CLK_SOURCE_NO_PRESCALER:
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_CLK_SOURCE_PRESCALER8:
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_CLK_SOURCE_PRESCALER64:
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_CLK_SOURCE_PRESCALER256:
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_CLK_SOURCE_PRESCALER1024:
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_EXT_CLK_SOURCE_T0_PIN_FALLING_EDGE:
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        CLEAR_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                case TMR_EXT_CLK_SOURCE_T0_PIN_RISING_EDGE:
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS02);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS01);
                        SET_BIT(TMR__UINT8_TCCR0_REG, TMR_TCCR0_CS00);
                        break;
                default:
                        break;
                }
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
        }
        return Local_CheckStatusReturnStatus;
}
Void __vector_11(Void) __attribute__((signal));
Void __vector_11(Void)
{
        static _uint16 Local__Uint16Counter = 0;

        Local__Uint16Counter++;
        if (Local__Uint16Counter == ((_uint16)Local__Float32NumberOfOVF + 1))
        {
                TMR__UINT8_TCNT0_REG = Local__Uint8_PrloadNum;
                Local__Uint16Counter = 0;
                if (TMR_PTF_VoidTIMEROVF != NULL)
                {
                        TMR_PTF_VoidTIMEROVF();
                }
                else
                {
                        /* DO NOTHING */
                }
        }
        else
        {
                /* DO NOTHING */
        }
}
Void __vector_10(Void) __attribute__((signal));
Void __vector_10(Void)
{
        static _uint16 Local__Uint16Counter = 0;

        Local__Uint16Counter++;
        if (Local__Uint16Counter == 10000)
        {
                Local__Uint16Counter = 0;
                if (TMR_PTF_VoidTIMERCTC != NULL)
                {
                        TMR_PTF_VoidTIMERCTC();
                }
                else
                {
                        /* DO NOTHING */
                }
        }
        else
        {
                /* DO NOTHING */
        }
}
CheckStatus TMR_CheckStatusTimer0OVFSetCallBack(Void (*Copy_PTF)(Void))
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        if (Copy_PTF != NULL)
        {
                TMR_PTF_VoidTIMEROVF = Copy_PTF;
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
        }
        return Local_CheckStatusReturnStatus;
}
CheckStatus TMR_CheckStatusTimer0CTCSetCallBack(Void (*Copy_PTF)(Void))
{
        CheckStatus Local_CheckStatusReturnStatus = CHECK_SUCCESS;
        if (Copy_PTF != NULL)
        {
                TMR_PTF_VoidTIMERCTC = Copy_PTF;
        }
        else
        {
                Local_CheckStatusReturnStatus = CHECK_FAIL;
        }
        return Local_CheckStatusReturnStatus;
}

Void TMR_CHANGE_OCRC0(_uint8 Copy__Uint8OCR0Value)
{
TMR__UINT8_OCRO_REG = Copy__Uint8OCR0Value;
}
Void TMR_VoidTimer1INIT(Void)
{

/* timer1 selectmode 14=>ICR1 Top Value */
SET_BIT(TMR__UINT8_TCCR1A_REG,1);
CLEAR_BIT(TMR__UINT8_TCCR1A_REG,0);
SET_BIT(TMR__UINT8_TCCR1B_REG,4);
SET_BIT(TMR__UINT8_TCCR1B_REG,3);

/*  Channel A => Noninverting */
SET_BIT(TMR__UINT8_TCCR1A_REG,7);
CLEAR_BIT(TMR__UINT8_TCCR1A_REG,6);

/* max value to overflow  */
TMR__UINT16_ICR1L_REG = 19999;

/*  select  prescaler */
CLEAR_BIT(TMR__UINT8_TCCR1B_REG,2);
SET_BIT(TMR__UINT8_TCCR1B_REG,1);
CLEAR_BIT(TMR__UINT8_TCCR1B_REG,0);
}



Void TMR_VOidTimer1SEtCompareMatchValue(_uint16 copy_value)
{
	TMR__UINT16_OCR1AL_REG =copy_value;
}
