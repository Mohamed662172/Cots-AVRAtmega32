/********************************************************/                                                                          
/*************** Name     :ELabbas salah ****************/                                                                          
/*************** Date     :  23/05/2020  ****************/                                                                          
/*************** SWC      :    DIO       ****************/                                                                          
/*************** Version  :    V1.0      ****************/                                                                          
/********************************************************/                                                                          
#ifndef DIO_CONFIG_H                                                                                                                
#define DIO_CONFIG_H                                                                                                                
                                                                                                                                    
/* Options : 1- DIO__UINT8_INITIAL_INPUT                                                                                            
	     2- DIO__UINT8_INITIAL_OUTPUT                                                                                           
*/                                                                                                                                  
                                                                                                                                    
#define DIO__UINT8_PA0_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PA1_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PA2_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PA3_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PA4_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
#define DIO__UINT8_PA5_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
#define DIO__UINT8_PA6_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
#define DIO__UINT8_PA7_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
                                                                                                                                    
#define DIO__UINT8_PB0_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PB1_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
#define DIO__UINT8_PB2_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
#define DIO__UINT8_PB3_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT                                                      
#define DIO__UINT8_PB4_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PB5_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PB6_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PB7_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
                                                                                                                                    
#define DIO__UINT8_PC0_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PC1_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PC2_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PC3_INITIAL_DIRECTION              DIO__UINT8_INITIAL_INPUT
#define DIO__UINT8_PC4_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PC5_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PC6_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
#define DIO__UINT8_PC7_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT
                                                                                                                                    
#define DIO__UINT8_PD0_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD1_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD2_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD3_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD4_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD5_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD6_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
#define DIO__UINT8_PD7_INITIAL_DIRECTION              DIO__UINT8_INITIAL_OUTPUT                                                     
/*                                                                                                                                  
OPTIONS :                                                                                                                           
	  1-DIO__UINT8_INPUT_FLOATING                                                                                                   
	  2-DIO__UINT8_INPUT_PULLUP                                                                                                     
	  3-DIO__UINT8_OUTPUT_LOW
	  4-DIO__UINT8_OUTPUT_HIGH                                                                                                       
*/                                                                                                                                  
                                                                                                                                    
#define DIO__UINT8_PA0_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PA1_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PA2_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PA3_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PA4_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING                                                         
#define DIO__UINT8_PA5_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING                                                         
#define DIO__UINT8_PA6_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING                                                         
#define DIO__UINT8_PA7_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING                                                         
                                                                                                                                    
#define DIO__UINT8_PB0_INITIAL_VALUE              DIO__UINT8_OUTPUT_HIGH
#define DIO__UINT8_PB1_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING
#define DIO__UINT8_PB2_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING
#define DIO__UINT8_PB3_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING
#define DIO__UINT8_PB4_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING
#define DIO__UINT8_PB5_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING
#define DIO__UINT8_PB6_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING
#define DIO__UINT8_PB7_INITIAL_VALUE              DIO__UINT8_INPUT_FLOATING

#define DIO__UINT8_PC0_INITIAL_VALUE              DIO__UINT8_INPUT_PULLUP
#define DIO__UINT8_PC1_INITIAL_VALUE              DIO__UINT8_INPUT_PULLUP
#define DIO__UINT8_PC2_INITIAL_VALUE              DIO__UINT8_INPUT_PULLUP
#define DIO__UINT8_PC3_INITIAL_VALUE              DIO__UINT8_INPUT_PULLUP
#define DIO__UINT8_PC4_INITIAL_VALUE              DIO__UINT8_OUTPUT_HIGH
#define DIO__UINT8_PC5_INITIAL_VALUE              DIO__UINT8_OUTPUT_HIGH
#define DIO__UINT8_PC6_INITIAL_VALUE              DIO__UINT8_OUTPUT_HIGH
#define DIO__UINT8_PC7_INITIAL_VALUE              DIO__UINT8_OUTPUT_HIGH
                                                                                                                                    
#define DIO__UINT8_PD0_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD1_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD2_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD3_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD4_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD5_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD6_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
#define DIO__UINT8_PD7_INITIAL_VALUE              DIO__UINT8_OUTPUT_LOW
                                                                                                                                    
#endif                                                                                                                              
                                                                                                                                    
