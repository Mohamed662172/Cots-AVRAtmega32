/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  19/09/2020  ****************/                                                                          
/*************** SWC      :   ADC        ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/  

#ifndef  ADC_INTERFACE_H_
#define  ADC_INTERFACE_H_


#define  ADC_CHANNEL_0     0
#define  ADC_CHANNEL_1     1
#define  ADC_CHANNEL_2     2
#define  ADC_CHANNEL_3     3
#define  ADC_CHANNEL_4     4
#define  ADC_CHANNEL_5     5
#define  ADC_CHANNEL_6     6
#define  ADC_CHANNEL_7     7
#define  ADC_CHANNEL_8     8
#define  ADC_CHANNEL_9     9
#define  ADC_CHANNEL_10    10
#define  ADC_CHANNEL_11    11
#define  ADC_CHANNEL_12    12
#define  ADC_CHANNEL_13    13
#define  ADC_CHANNEL_14    14
#define  ADC_CHANNEL_15    15
#define  ADC_CHANNEL_16    16
#define  ADC_CHANNEL_17    17
#define  ADC_CHANNEL_18    18
#define  ADC_CHANNEL_19    19
#define  ADC_CHANNEL_20    20
#define  ADC_CHANNEL_21    21
#define  ADC_CHANNEL_22    22
#define  ADC_CHANNEL_23    23
#define  ADC_CHANNEL_24    24
#define  ADC_CHANNEL_25    25
#define  ADC_CHANNEL_26    26
#define  ADC_CHANNEL_27    27
#define  ADC_CHANNEL_28    28
#define  ADC_CHANNEL_29    29
#define  ADC_CHANNEL_30    30
#define  ADC_CHANNEL_31    31
Void ADC_VoidInit(Void);

Void ADC_VoidDisable(Void);

CheckStatus  ADC_CheckStatusGetDigigtalValueSynchNonBlocking ( _uint8 Copy__Uint8ChannelId, _uint16 *Copy__Uint8DigitalValue );

#endif
