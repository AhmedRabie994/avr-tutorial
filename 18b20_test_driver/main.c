/*
 * main.c
 *
 *  Created on: Mar 27, 2020
 *      Author: user1
 */

#include "DS18B20.h"
#include "LCD.h"


int main(void){

	LCD_init();
	double  temp;

	while(1){
    LCD_gotoRowColumn(1,1);
    LCD_print_str("temperature=");
    temp=ds18b20_gettemp();
    LCD_gotoRowColumn(2,1);
    LCD_FLOATToString(temp,6,3);
    _delay_ms(300);
	}}
