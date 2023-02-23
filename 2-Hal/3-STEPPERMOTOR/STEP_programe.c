
/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include"STEP_private.h"
#include"STEP_interface.h"
#include"STEP_config.h"

#define STEPPER_FULL_ANGEL     360

CheckStatus STEP_CheckStatusStepperMotorRottor(_uint16 Copy__Uint8StepperAngel,_uint8 Copy__Uint8StepperDirection)
{
        CheckStatus Local_CheckStausReturnValue = CHECK_SUCCESS;
        _uint16     Local__Uint16AngelPerFullStep=STEP_STRIDE_ANGLE*2;
        _uint32     Local__Uint32NumberOfStepsFor360=(_uint32)STEPPER_FULL_ANGEL/(_uint32)Local__Uint16AngelPerFullStep;  //2048
        _uint32     Local__Uint32NumberOfSteps=(_uint32)(((_uint32)Copy__Uint8StepperAngel * (_uint32)Local__Uint32NumberOfStepsFor360) / STEPPER_FULL_ANGEL);
                    Local__Uint32NumberOfSteps = Local__Uint32NumberOfSteps/4;
        _uint16     Local__Uint16IndexCounter = 0 ;
        
        if((Copy__Uint8StepperAngel<=STEPPER_FULL_ANGEL) && ( (Copy__Uint8StepperDirection == COUNTER_CLK_WISE) || (Copy__Uint8StepperDirection == CLK_WISE)))
        {
        	     
          if(Copy__Uint8StepperDirection == CLK_WISE)
          {
              for ( Local__Uint16IndexCounter = 0; Local__Uint16IndexCounter < Local__Uint32NumberOfSteps ;++Local__Uint16IndexCounter)
              {
                         DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_LOW);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_HIGH);
	                 _delay_ms(2);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_LOW);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_HIGH);
	                 _delay_ms(2);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_LOW);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_HIGH);
	                 _delay_ms(2);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_LOW);
	                 _delay_ms(2);

                      
              }
          }
          else if (Copy__Uint8StepperDirection == COUNTER_CLK_WISE)
          {
              for ( Local__Uint16IndexCounter = 0; Local__Uint16IndexCounter < Local__Uint32NumberOfSteps ;++Local__Uint16IndexCounter)
                {
                  	 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_LOW);
	                 _delay_ms(2);
                         DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_LOW);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_HIGH);
	                 _delay_ms(2);
                         DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_LOW);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_HIGH);
	                 _delay_ms(2);
                         DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_BLUE,DIO__UINT8_LOW);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_PINK,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_YELLOW,DIO__UINT8_HIGH);
	                 DIO__CheckStatusSetPinValue(STEPER_MOTOR_PORT,STEPER_MOTOR_ORANGE,DIO__UINT8_HIGH);
	                 _delay_ms(2);
                }              
                
          }
          else
          {
                /*  DO NOTHING  */
          }
          
        }
        else 
        {
                Local_CheckStausReturnValue = CHECK_FAIL; 
        }
                return Local_CheckStausReturnValue;
}



