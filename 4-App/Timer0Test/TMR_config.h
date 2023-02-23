/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  26/05/2020  ****************/
/*************** SWC      :   TMR0       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/
/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  26/05/2020  ****************/
/*************** SWC      :   TMR0       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef TMR_CONFIG_H_
#define TMR_CONFIG_H_

/*
   FREQENCY OF CPU
*/
#define TMR__UINT32_F_CPU     8000000UL


/*
option of wave generation mode :
        1-TMR_IN_NORMAL_MODE
        2-TMR_IN_PWM_MODE       (PHASE CORRECT MODE)
        3-TMR_IN_CTC_MODE
        4-TMR_IN_FAST_PWM_MODE   
*/

#define    TMR__UINT8_MODE_TIMER        TMR_IN_FAST_PWM_MODE

/*
option  of COMPARE MATCH OUTPUT IN  NORMAL AND CTC MODE
   1-TMR_CMOMODE_OC0_DISCONNECTED
   2-TMR_CMOMODE_OC0_TOGGLE
   3-TMR_CMOMODE_OC0_SET
   4-TMR_CMOMODE_OC0_CLEAR
*/
#define    TMR__UINT8_COMPARE_MATCH_OUTPUT     TMR_CMOMODE_OC0_DISCONNECTED 
/*
option of COMPARE MATCH OUTPUT IN  FAST PWM MODE
   0-TMR_CMOMODE_OC0_DISCONNECTED
   1-TMR_CMOMODE_OC0_SET_FAST_PWM            
   2-TMR_CMOMODE_OC0_CLEAR_FAST_PWM        
*/
#define    TMR__UINT8_COMPARE_MATCH_OUTPUT_FAST_PWM  TMR_CMOMODE_OC0_SET_FAST_PWM
/*
option of COMPARE MATCH OUTPUT IN  FAST PWM MODE
   0-TMR_CMOMODE_OC0_DISCONNECTED
   1-TMR_CMOMODE_OC0_SET_PHASE_CORRECT       fun(Clear OC0 on compare match when up-counting.Set OC0 on compare match when downcounting)          
   2-TMR_CMOMODE_OC0_CLEAR_PHASE_CORRECT     fun(Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting)   
*/
#define    TMR__UINT8_COMPARE_MATCH_OUTPUT_PHASE_CORRECT  TMR_CMOMODE_OC0_SET_PHASE_CORRECT

/*
 option SELECT CLK SOURCE 
   1-TMR_NO_CLK_SOURCE
   2-TMR_CLK_SOURCE_NO_PRESCALER
   3-TMR_CLK_SOURCE_PRESCALER8
   4-TMR_CLK_SOURCE_PRESCALER64
   5-TMR_CLK_SOURCE_PRESCALER256
   6-TMR_CLK_SOURCE_PRESCALER1024
   7-TMR_EXT_CLK_SOURCE_T0_PIN_FALLING_EDGE
   8-TMR_EXT_CLK_SOURCE_T0_PIN_RISING_EDGE
*/
#define   TMR__UINT8_SELECT_TIMER       TMR_CLK_SOURCE_PRESCALER8

#endif
