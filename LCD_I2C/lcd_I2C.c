/*
 * lcd_4bit.c
 *
 * Created: 7/24/2017 10:35:17 PM
 *  Author: Ahmed
 */ 
#include "lcd_I2C.h"



//**********************************************************************************************
void lcd_command(unsigned char cmd){
	 unsigned char commed;
	I2C_Start(pcf8574_address);
	commed=(commed & 0x0F)|(cmd & 0xF0);
	commed&=~(1<<lcd_RS);
	commed&=~(1<<lcd_RW);
	commed|=(1<<lcd_EN);
	I2C_Write(commed);
	_delay_us(50);
	commed&=~(1<<lcd_EN);
	I2C_Write(commed);
	_delay_us(50);
	commed =(commed & 0x0F)|(cmd<<4);
	commed|=(1<<lcd_EN);
	I2C_Write(commed);
	_delay_us(50);
	commed&=~(1<<lcd_EN);
	I2C_Write(commed);
	I2C_Stop();

}

//********************************************************************************************
void lcd_data(unsigned char data){
 unsigned char datas;
	I2C_Start(pcf8574_address);
	datas=(datas & 0x0F)|(data & 0xF0);
	datas|=(1<<lcd_RS);
	datas&=~(1<<lcd_RW);
	datas|=(1<<lcd_EN);
	I2C_Write(datas);
	_delay_us(50);
	datas&=~(1<<lcd_EN);
	I2C_Write(datas);
	_delay_us(50);
	datas =(datas & 0x0F)|(data<<4);
	datas|=(1<<lcd_EN);
	I2C_Write(datas);
	_delay_us(100);
	datas&=~(1<<lcd_EN);
	I2C_Write(datas);
	I2C_Stop();

}
//***********************************************************************************************
//function for lcd initialize.
//lcd_init();
void lcd_init(){
        I2C_Init();
	lcd_command(0x33);
	_delay_us(50);
	lcd_command(0x32);
	_delay_us(50);
	lcd_command(0x28);
	_delay_us(50);
	lcd_command(0x0E);
	_delay_us(50);
	lcd_command(0x01);
	_delay_us(2000);
	lcd_command(0x06);
}
//*********************************************************************************************************
//function to locate the position.
//lcd_goto_xy(row,columm);
//line 1 of lcd=row 1. ,line2 of lcd=row2
//columm 1 of lcd =columm 1., columm 16 of lcd =columm 16.

void lcd_goto_xy(unsigned char row,unsigned char columm){
	unsigned char fristcharadr[]={0x80,0xC0,0x90,0xD0};
		lcd_command(fristcharadr[row-1]+(columm-1));
		_delay_us(100);
	}
//***********************************************************************************************************
//function to put what u need.
// lcd_print("hallo");
 void lcd_print(char *text){
	while(*text>0){
		lcd_data(*text++);
	}
}

//************************************************************************************************************
//function to clear lcd. 
//lcd_CLEAR();.
void lcd_CLEAR(){
	lcd_command(0x01);
	_delay_ms(2);}
//*************************************************************************************************************
//function to cancel the cursor.
//lcd_curcor_off();
void lcd_curcor_off(){
	lcd_command(0x0c);
	_delay_us(100);
}
//*************************************************************************************************************
	
