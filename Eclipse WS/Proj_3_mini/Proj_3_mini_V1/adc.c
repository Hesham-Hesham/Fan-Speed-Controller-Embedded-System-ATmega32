/*
 * adc.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Hesham
 */

#include <avr/io.h>

#include "adc.h"
#include "std_types.h"
#include "common_macros.h"


/*
 * Description :
 * Responsible for initializing the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr){

	//Set the Vref as AVCC,AREF, or internal 2.56v
	ADMUX= (ADMUX & 0x3F) | ( ( (Config_Ptr->ref_volt)<<6) & (~0x3F) );

	CLEAR_BIT(ADMUX,ADLAR);	//ADC Left Adjust

	//Choose ADC0 in the initialization
	CLEAR_BIT(ADMUX,MUX0);
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX3);

	SET_BIT(ADCSRA,ADEN);	//Enable the ADC

	CLEAR_BIT(ADCSRA,ADIE);	//Disable interrupt

	//Choose a prescaler that sets Fadc to 50 kHZ<-->200 kHZ
	ADCSRA = (ADCSRA&0xF8) | ( ( (Config_Ptr->prescaler)<<0) & (~0xF8) );

}



/*
 * Description :
 * Responsible for reading analog data from an ADC channel
 * and converting it to a digital value using the ADC driver.
 */
uint16 ADC_readChannel(ADC_Channel ch_num){
	ADMUX=(ADMUX& 0xE0)| (ch_num & 0x1F);	//insert channel number into MUX0 <---> MUX4
	SET_BIT(ADCSRA,ADSC);					//Start conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); 		//Wait for flag
	CLEAR_BIT(ADCSRA,ADIF);					//Reset the flag for next time
	return ADC;								//Return the 10 bit result


}


