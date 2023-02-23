/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  03/10/2020  ****************/                                                                          
/*************** SWC      :    WDT       ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/

#ifndef  WDT_PRIVATE_H_
#define  WDT_PRIVATE_H_

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
#define WDT_OSC_16K_CYCLE    1   //   3v=17.1ms   5v=16.3ms    
#define WDT_OSC_32K_CYCLE    2   //   3v=34.3ms   5v=32.5ms
#define WDT_OSC_64K_CYCLE    3   //   3v=68,5ms   5v=65ms
#define WDT_OSC_128K_CYCLE   4   //   3v=0.14s    5v=0.13s
#define WDT_OSC_256K_CYCLE   5   //   3v=0.27s    5v=0.26s
#define WDT_OSC_512K_CYCLE   6   //   3v=0.55s    5v=0.52s
#define WDT_OSC_1024K_CYCLE  7   //   3v=1.1s     5v=1.0s
#define WDT_OSC_2048K_CYCLE  8   //   3v=2.2s     5v=2.1s

#endif