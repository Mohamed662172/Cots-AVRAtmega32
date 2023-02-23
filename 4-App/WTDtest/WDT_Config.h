/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  03/10/2020  ****************/                                                                          
/*************** SWC      :    WDT       ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/

#ifndef  WDT_CONFIG_H_
#define  WDT_CONFIG_H_

/*
 Option WDT PRESCALER:
       1-WDT_OSC_16K_CYCLE       //   3v=17.1ms   5v=16.3ms    
       2-WDT_OSC_32K_CYCLE       //   3v=34.3ms   5v=32.5ms
       3-WDT_OSC_64K_CYCLE       //   3v=68,5ms   5v=65ms
       4-WDT_OSC_128K_CYCLE      //   3v=0.14s    5v=0.13s
       5-WDT_OSC_256K_CYCLE      //   3v=0.27s    5v=0.26s
       6-WDT_OSC_512K_CYCLE      //   3v=0.55s    5v=0.52s
       7-WDT_OSC_1024K_CYCLE     //   3v=1.1s     5v=1.0s
       8-WDT_OSC_2048K_CYCLE     //   3v=2.2s     5v=2.1s
       
*/

#define WDT_UINT8_WDT_PRESCALER_TIMER   WDT_OSC_16K_CYCLE
#endif

