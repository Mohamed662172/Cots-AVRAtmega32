


#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_



#define KPAD__UINT8_PORT         DIO__UINT8_PORTC


#define KPAD__UINT8_COL1          DIO__UINT8_PIN0
#define KPAD__UINT8_COL2          DIO__UINT8_PIN1
#define KPAD__UINT8_COL3          DIO__UINT8_PIN2
#define KPAD__UINT8_COL4          DIO__UINT8_PIN3

#define KPAD__UINT8_ROW1          DIO__UINT8_PIN4
#define KPAD__UINT8_ROW2          DIO__UINT8_PIN5
#define KPAD__UINT8_ROW3          DIO__UINT8_PIN6
#define KPAD__UINT8_ROW4          DIO__UINT8_PIN7

#define KPAD_A_UINT8VALUE        { {'1','4','7','*'},\
                                   {'2','5','8','0'},\
                                   {'3','6','9','#'},\
                                   {'A','B','C','D'} \
                                 }

#endif
