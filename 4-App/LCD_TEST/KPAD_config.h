/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     : 28/08/2020   ****************/
/*************** SWC      :   KEYPAD     ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_



#define KPAD__UINT8_PORT         DIO__UINT8_PORTA


#define KPAD__UINT8_COL1          DIO__UINT8_PIN7                      
#define KPAD__UINT8_COL2          DIO__UINT8_PIN6
#define KPAD__UINT8_COL3          DIO__UINT8_PIN5
#define KPAD__UINT8_COL4          DIO__UINT8_PIN4

#define KPAD__UINT8_ROW1          DIO__UINT8_PIN3
#define KPAD__UINT8_ROW2          DIO__UINT8_PIN2
#define KPAD__UINT8_ROW3          DIO__UINT8_PIN1
#define KPAD__UINT8_ROW4          DIO__UINT8_PIN0

#define KPAD_A_UINT8VALUE        { {'S',' ','U',' '},\
                                   {'C','L','D','R'},\
                                   {'R',' ',' ',' '},\
                                   {' ',' ',' ',' '} \
                                 }

#endif
