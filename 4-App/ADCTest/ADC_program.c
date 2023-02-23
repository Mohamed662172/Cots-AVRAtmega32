/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  19/09/2020  ****************/                                                                          
/*************** SWC      :   ADC        ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/  

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* Mcal */
#include"ADC_interface.h"
#include"ADC_config.h"
#include"ADC_private.h"

#define  ADC_MAX_NUMBER_OF_CHANNALE   32
#define  ADC_CHANNEL_CLEAR(REG)      REG &= (0b11100000)   
Void ADC_VoidDisable(Void)
{
        /*1- Disable Peripheral */
        CLEAR_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADEN);
        
}

Void ADC_VoidInit(Void)
{
        /* 1-Select Vref = Vcc */
         SET_BIT(ADC_UINT8_ADMUX_REG,ADMUX_REFS0);
        /* 2-Select Right adjust */
		CLEAR_BIT(ADC_UINT8_ADMUX_REG,ADMUX_ADLAR);
        /* 3-disable AutoTrigger  */ 
         CLEAR_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADATE);
        /* 4-CLK/64 */
         SET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADPS2);
         SET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADPS1);
         CLEAR_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADPS0);
        /* 5-Enable ADC Peripheral */
        SET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADEN);
}

CheckStatus  ADC_CheckStatusGetDigigtalValueSynchNonBlocking ( _uint8 Copy__Uint8ChannelId, _uint16 *Copy__Uint8DigitalValue )
{
             CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
             _uint32   Local__Uint32TimeOutCounter = 0;
             if((Copy__Uint8ChannelId < ADC_MAX_NUMBER_OF_CHANNALE) && (Copy__Uint8DigitalValue != NULL)  )
             {
                        /* empety ADMUX Reg */
                        ADC_CHANNEL_CLEAR(ADC_UINT8_ADMUX_REG);
                        /* select channel */
                        ADC_UINT8_ADMUX_REG |= Copy__Uint8ChannelId;
                        /* start conversion */
                        SET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADSC);
                        /* waiting flag = 1 */
                        while ((!GET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADIF)) && (Local__Uint32TimeOutCounter < ADC__UINT32_TIME_OUT_RATE))
                        {
                                Local__Uint32TimeOutCounter++ ;
                        }
                        if((Local__Uint32TimeOutCounter >= ADC__UINT32_TIME_OUT_RATE) || (GET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADIF) == 0))
                        {
                        		Local_CheckStausReturnValue =CHECK_FAIL;
                        }
                        else
                        {
                          *Copy__Uint8DigitalValue = ADC_UINT16_ADCL_REG;
                          /* Clear Flag */
                          SET_BIT(ADC_UINT8_ADCSRA_REG,ADCSRA_ADIF);
                        }
             }
             else
             {
                Local_CheckStausReturnValue = CHECK_FAIL;                     
             }
             return Local_CheckStausReturnValue;
             
}
