/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  19/09/2020  ****************/                                                                          
/*************** SWC      :   ADC        ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/  

#ifndef  ADC_PRIVATE_H_
#define  ADC_PRIVATE_H_




/* Define  ADC   Register */ 

#define   ADC_UINT8_ADMUX_REG     *((volatile _uint8* const)0x27)
#define   ADC_UINT8_ADCSRA_REG    * ((volatile _uint8* const)0x26)
#define   ADC_UINT8_ADCH_REG      *((volatile _uint8* const)0x25)
#define   ADC_UINT16_ADCL_REG     *((volatile _uint16* const)0x24)
#define   ADC_UINT8_SFIOR_REG     *((volatile _uint8* const)0x50)

/*
 * 
 *   ADMUX  BIT REG.  Config 
 * 
 * 
 */ 
#define   ADMUX_REFS1    7
#define   ADMUX_REFS0    6
#define   ADMUX_ADLAR    5
/* 
 *     
 * all channerl option are 32  maping to this register 
 * 
 * 
 */

#define   ADMUX_MUX4     4
#define   ADMUX_MUX3     3
#define   ADMUX_MUX2     2
#define   ADMUX_MUX1     1
#define   ADMUX_MUX0     0
/*
 * 
 *   ADCSRA  BIT REG.  Config 
 * 
 * 
 */ 

#define   ADCSRA_ADEN    7
#define   ADCSRA_ADSC    6
#define   ADCSRA_ADATE   5
#define   ADCSRA_ADIF    4
#define   ADCSRA_ADIE    3
#define   ADCSRA_ADPS2   2
#define   ADCSRA_ADPS1   1
#define   ADCSRA_ADPS0   0
/*
 * 
 *   SFIOR  BIT REG.  Config 
 * 
 * 
 */ 
#define    SFIOR_ADTS2  7
#define    SFIOR_ADTS1  6
#define    SFIOR_ADTS0  5




#endif
