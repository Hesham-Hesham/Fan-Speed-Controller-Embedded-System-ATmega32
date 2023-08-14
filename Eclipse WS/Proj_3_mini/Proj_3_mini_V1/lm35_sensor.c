 /******************************************************************************
 * lm35_sensor.c
 *
 * Created on: Apr 29, 2023
 * Author:  Hesham
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "adc.h"

/*
 * Description :
 * Responsible for calculating the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	//8-bit variable because the temperature in this application won't pass 255 degrees C
	uint8 temp_value = 0;

	//16-bit variable because the adc return value is 10 bits
	uint16 adc_value = 0;

	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);		//read the ADC value from the predefined channel

	//convert the digital value from the ADC to a temperature value
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

