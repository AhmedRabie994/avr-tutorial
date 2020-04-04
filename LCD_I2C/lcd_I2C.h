/*
 * lcd_4bit.h
 *
 * Created: 7/24/2017 10:38:39 PM
 *  Author: Ahmed
 */

#include "I2C.h"


#define SCL_CLK 400000L
#define pcf8574_address 0x40


#define lcd_RS 0
#define lcd_RW 1
#define lcd_EN 2
#ifndef LCD_I2C_H_
#define LCD_I2C_H_

void lcd_command(unsigned char cmd);
void lcd_data(unsigned char data);
//***********************************************************************************************
//function for lcd initialize.
//lcd_init();
void lcd_init();
//*********************************************************************************************************
//function to locate the position.
//lcd_goto_xy(row,columm);
//line 1 of lcd=row 1. ,line2 of lcd=row2
//columm 1 of lcd =columm 1., columm 16 of lcd =columm 16.
void lcd_goto_xy(unsigned char row,unsigned char columm);
//***********************************************************************************************************
//function to put what u need.
// lcd_print("hallo");
void lcd_print(char *text);
//************************************************************************************************************
//function to clear lcd.
//lcd_CLEAR();.
void lcd_CLEAR();
//*************************************************************************************************************
//function to cancel the cursor.
//lcd_curcor_off();
void lcd_curcor_off();



#endif /* LCD_4BIT_H_ */
