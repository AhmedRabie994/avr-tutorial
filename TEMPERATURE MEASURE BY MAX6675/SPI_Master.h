/*
 * SPI_Master_LIB.h
 *
 * Created: 9/8/2017 10:34:09 PM
 *  Author: Ahmed
 */ 

#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"



#define MOSI 5
#define MISO 6
#define SCK 7
#define SS 4



void SPI_M_Init();
void SPI_M_Write(char data);
char SPI_M_Read();
void SPI_SS_enable();
void SPI_SS_disable();




#endif /* SPI_MASTER_H_ */
