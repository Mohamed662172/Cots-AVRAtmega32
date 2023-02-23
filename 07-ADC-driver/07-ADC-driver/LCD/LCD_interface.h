/*
 * LCD_interface.h
 *
 *  Created on: Apr 30, 2022
 *      Author: mazen
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_


#define LCD_CLEAR   0b00000001


void LCD_Init(void);
void LCD_SendCommand(u8 command);
void LCD_SendChar(char c);

void LCD_PrintString(char str[]);
void LCD_PrintNumber(s32 num);
void LCD_ClearDisplay(void);


/* custom charachter functions */
void LCD_DisplayCustomChar(u8 address);
void LCD_SaveCustomChar(u8 address, u8 array[]);

/* cursor movinf functions */
void LCD_SetCursorPosition(u8 linePos, u8 lineNo);









#endif /* LCD_LCD_INTERFACE_H_ */
