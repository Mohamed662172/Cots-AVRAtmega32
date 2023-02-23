/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  26/05/2020  ****************/
/*************** SWC      :   TMR0       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

#ifndef  TMR_PRIVATE_H_
#define  TMR_PRIVATE_H_
#define  TMR__UINT8_TCCR0_REG      *((volatile _uint8* const)0x53)
#define  TMR__UINT8_TCNT0_REG      *((volatile _uint8* const)0x52)
#define  TMR__UINT8_OCRO_REG       *((volatile _uint8* const)0x5C)
#define  TMR__UINT8_TIMSK_REG      *((volatile _uint8* const)0x59)
#define  TMR__UINT8_TIFR_REG       *((volatile _uint8* const)0x58)

/*
        bit of TCCR0
*/
#define  TMR_TCCR0_FOC0    7
#define  TMR_TCCR0_WGM00   6
#define  TMR_TCCR0_COM01   5
#define  TMR_TCCR0_COM00   4
#define  TMR_TCCR0_WGM01   3
#define  TMR_TCCR0_CS02    2
#define  TMR_TCCR0_CS01    1
#define  TMR_TCCR0_CS00    0


/*
        bit of TIFR
*/
#define  TMR_TIFR_OCOF0    1
#define  TMR_TIFR_TOV0    0

/*
        bit of TIMSK
*/
#define  TMR_TIMSK_OCIE0    1
#define  TMR_TIMSK_TOIF0    0
/*
   WAVE Form Generation mode 
*/
#define TMR_IN_NORMAL_MODE    1
#define TMR_IN_PWM_MODE       2
#define TMR_IN_CTC_MODE       3
#define TMR_IN_FAST_PWM_MODE  4
/*
  COMPARE MATCH OUTPUT OC0
  NORMAL MODE AND CTC MODE 
*/
#define TMR_CMOMODE_OC0_DISCONNECTED  1
#define TMR_CMOMODE_OC0_TOGGLE        2
#define TMR_CMOMODE_OC0_SET           3
#define TMR_CMOMODE_OC0_CLEAR         4

/*
  COMPARE MATCH OUTPUT OC0
  FAST PWM MODE 
*/
#define TMR_CMOMODE_OC0_SET_FAST_PWM           3
#define TMR_CMOMODE_OC0_CLEAR_FAST_PWM         4
/*
  COMPARE MATCH OUTPUT OC0
  PWM MODE   (PHASE CORRECT) 
*/
#define TMR_CMOMODE_OC0_SET_PHASE_CORRECT           3
#define TMR_CMOMODE_OC0_CLEAR_PHASE_CORRECT         4
/*
   SELECT TIMER 
*/
#define TMR_NO_CLK_SOURCE                         0
#define TMR_CLK_SOURCE_NO_PRESCALER               1
#define TMR_CLK_SOURCE_PRESCALER8                 2
#define TMR_CLK_SOURCE_PRESCALER64                3
#define TMR_CLK_SOURCE_PRESCALER256               4
#define TMR_CLK_SOURCE_PRESCALER1024              5
#define TMR_EXT_CLK_SOURCE_T0_PIN_FALLING_EDGE    6
#define TMR_EXT_CLK_SOURCE_T0_PIN_RISING_EDGE     7

#endif