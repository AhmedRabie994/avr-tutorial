/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: user1
 */


#include"LCD.h"
#include "SPI_Master.h"





int main(void){
    uint8 temp_l,temp_h;
    uint16 temp,tempe;
    SPI_M_Init();
	LCD_init();
    while(1){
    LCD_gotoRowColumn(1,1);
    LCD_print_str("tempature=");
    SPI_SS_enable();
    _delay_ms(1);
    temp_h=SPI_M_Read();
    temp_l=SPI_M_Read();
    SPI_SS_disable();
    temp=(temp_h<<8)|temp_l;
    temp=temp&0x7fff;
    temp>>=2;
    tempe=(temp/4)-24;
    LCD_gotoRowColumn(1,12);
    LCD_intgerToString(tempe);
    _delay_ms(500);
    LCD_clearScreen();
    }

}
