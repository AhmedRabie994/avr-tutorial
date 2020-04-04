 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Ahmed Rabie
 *
 *******************************************************************************/

#include "ADC.h"

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 G_AdcResult = 0;

/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/
ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	G_AdcResult = ADC;
}
/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr){
	DDRA =0x00;
	/* ADMUX Register Bits Description:
	 * insert the required  voltage reference value in the Last two bits (REFS1:0)
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX =(ADMUX&0x00)|((Config_Ptr->REF)<<REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = insert the required type of adc( enable enterrupt or not).
	 * ADPS2:0 = insert the required clock for ADC.
	 */
	ADCSRA = (1<<ADEN)|((Config_Ptr->TYPE)<<ADIE)|((Config_Ptr->CLOCK)<<ADPS0);
}
uint16 ADC_readChannel(uint8 channel_num){

	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
		ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
		ADMUX = ADMUX | channel_num; /* choose the correct channel by setting the channel number in MUX4:0 bits */
		SET_BIT(ADCSRA,ADSC); /* start conversion write '1' to ADSC */
		while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
		SET_BIT(ADCSRA,ADIF); /* clear ADIF by write '1' to it :) */
		return (ADC); /* return the data register */
}
void ADC_readChannel_Interrupt(uint8 channel_num){

		channel_num &= 0x07; /* channel number must be from 0 --> 7 */
				ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
				ADMUX = ADMUX | channel_num; /* choose the correct channel by setting the channel number in MUX4:0 bits */
				SET_BIT(ADCSRA,ADSC); /* start conversion write '1' to ADSC */

}





