 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Ahmed Rabie
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{/*
 AREF, Internal Vref turned off
 AVCC with external capacitor at AREF pin
 Reserved
 Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
	AREF,AVCC,R,Internal
}Adc_Refence;

typedef enum
{
	FCLOCK_2,FCLOCK_2_2,FCLOCK_4,FCLOCK_8,FCLOCK_16,FCLOCK_32,FCLOCK_64,FCLOCK_128
}Adc_clock;

typedef enum
{
	Polling,Interrupt
}Adc_type;


typedef struct
{
	Adc_Refence REF;
	Adc_clock CLOCK;
	Adc_type TYPE;
}ADC_ConfigType;

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 G_AdcResult;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ADC driver
 * 	1. Set the required Adc_Refence.
 * 	2. Set the required Adc_clock.
 * 	3. Set the ADC TYPE.
 * 	*/
void ADC_init(const ADC_ConfigType *Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * by using Polling in TYPE.
 */
uint16 ADC_readChannel(uint8 channel_num);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * by using Interrupt in TYPE.
 */
void ADC_readChannel_Interrupt(uint8 channel_num);

#endif /* ADC_H_ */


