/*
 * main.c
 *
 *  Created on: Apr 4, 2020
 *      Author: user1
 */


#include"lcd_I2C.h"


int main(void){
	lcd_init();


while(1){
	lcd_goto_xy(1,5);
	lcd_print("hallo ");
	lcd_goto_xy(2,5);
	lcd_print("ahmed ");

}


}
