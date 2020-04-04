

#include"ADC.h"
#include"LCD.h"


int main(void){
	uint16 l_adc_value=0;
	ADC_ConfigType ADC_config={AVCC,FCLOCK_8,Interrupt};
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	ADC_init(&ADC_config);
    LCD_init();
    while(1){
    	LCD_gotoRowColumn(1,1);
    	LCD_print_str("Adc value=");
    	ADC_readChannel_Interrupt(1);
    	l_adc_value=G_AdcResult;
        LCD_gotoRowColumn(1,11);
        LCD_intgerToString(l_adc_value);
_delay_ms(90);
    }
}


