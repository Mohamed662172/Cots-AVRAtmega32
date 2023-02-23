/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  03/10/2020  ****************/                                                                          
/*************** SWC      :    WDT       ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/


/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL LAYER*/
#include"WDT_intrface.h"
#include"WDT_private.h"
#include"WDT_Config.h"

/* interface the register */
#define    WDT_UINT8_WDTCR_REG      *((volatile _uint8*const)0x41)
#define    WDT_WDTCR_WDTOE   4        // whaqtch dog turn off enable 
#define    WDT_WDTCR_WDE     3
#define    WDT_WDTCR_WDP2    2
#define    WDT_WDTCR_WDP1    1
#define    WDT_WDTCR_WDP0    0
/* MACRO FUN */
#define    WDT_SET_TWICEBIT(REG,BIT0,BIT1)     REG =  (1<<BIT0) | (1<<BIT1)
/* WATCH DOG*/ 

Void WDT_VoidWhatchDogEnable(Void)
{ 
     SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDE);
#if(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_16K_CYCLE)
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);
 
#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_32K_CYCLE)
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);

#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_64K_CYCLE)
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);

#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_128K_CYCLE)
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);

#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_256K_CYCLE)
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);

#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_256K_CYCLE)
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);

#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_256K_CYCLE)
CLEAR_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);

#elif(WDT_UINT8_WDT_PRESCALER_TIMER == WDT_OSC_256K_CYCLE)
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP0);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP1);
SET_BIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDP2);
#endif 
     
}
Void WDT_VoidWhatchDogDisable(Void)
{
   WDT_SET_TWICEBIT(WDT_UINT8_WDTCR_REG,WDT_WDTCR_WDTOE,WDT_WDTCR_WDE);    
   WDT_UINT8_WDTCR_REG = 0x00;     
}