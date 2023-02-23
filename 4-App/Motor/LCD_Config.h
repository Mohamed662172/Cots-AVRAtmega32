/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/08/2020  ****************/
/*************** SWC      :    LCD       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*
SELECT :
          1-Control Port
          2-Register Select  PIN
          3-Read / Write  PIN
          4-Enable   PIN
          5-LCD_SHIFT_RIGHT
          6-LCD_SHIFT_LEFT
          7-LCD_8BIT_ACTIVATE
          8-LCD_4BIT_ACTIVATE
          9-LCD_LAST4BINS
         10-LCD_PRIM4BINS
*/

#define  LCD__UINT8_CONTROL_PORT       DIO__UINT8_PORTA
#define  LCD__UINT8_RS_PIN             DIO__UINT8_PIN0
#define  LCD__UINT8_RW_PIN             DIO__UINT8_PIN1  
#define  LCD__UINT8_E_PIN              DIO__UINT8_PIN2
#define  LCD__UINT8_DATA_PORT          DIO__UINT8_PORTD
#define  LCD__UINT8_DATA_PINS          LCD_LAST4BINS
#define  LCD__UINT8_SHIFT_ACTIVATE     LCD_SHIFT_RIGHT
#define  LCD__UINT8_BIT_ACTIVATE       LCD_4BIT_ACTIVATE

#define  LCD_ARRAY_UINT8_SPECIAL_CHAR1_VALUE  {           \
											  0b00011100,\
                                              0b00010100,\
                                              0b00011100,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
											  0b00000000,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR2_VALUE  {           \
											  0b00000111,\
                                              0b00001000,\
                                              0b00010110,\
                                              0b00010000,\
                                              0b00010100,\
                                              0b00001011,\
                                              0b00000111,\
											  0b00000000,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR3_VALUE  {           \
											 0b00011100,\
                                             0b00000010,\
                                             0b00001101,\
                                             0b00000001,\
                                             0b00000101,\
                                             0b00011010,\
                                             0b00011100,\
											 0b00000000,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR4_VALUE  {           \
											  0b00011111,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
											  0b00000000,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR5_VALUE  {           \
											  0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
											  0b00011111,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR6_VALUE  {           \
											  0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00001001,\
                                              0b00001001,\
                                              0b00011111,\
											  0b00000000,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR7_VALUE  {           \
											  0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000001,\
                                              0b00010001,\
                                              0b00011110,\
											  0b00000000,\
                                              }
#define  LCD_ARRAY_UINT8_SPECIAL_CHAR8_VALUE  {           \
											  0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
                                              0b00000000,\
											  0b00000000,\
                                              }
/*
** smile face **
0b00011100
0b00000010
0b00001101
0b00000001
0b00000101
0b00011010
0b00011100
0b00000000

***********
0b00000111
0b00001000
0b00010110
0b00010000
0b00010100
0b00001011
0b00000111
0b00000000

*/
#endif
