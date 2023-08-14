/*
 * adc.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Hesham
 */

#ifndef ADC_H_
#define ADC_H_


#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	ADC_EXTERNAL_AREF,ADC_AVCC,ADC_INTERNAL_2V56=3
}ADC_ReferenceVolatge;

typedef enum
{
	ADC_F_CPU_2=1,ADC_F_CPU_4,ADC_F_CPU_8,ADC_F_CPU_16,ADC_F_CPU_32,ADC_F_CPU_64,ADC_F_CPU_128
}ADC_Prescaler;

typedef enum
{
	ADC_CHANNEL_0,ADC_CHANNEL_1,ADC_CHANNEL_2,ADC_CHANNEL_3,ADC_CHANNEL_4,ADC_CHANNEL_5,ADC_CHANNEL_6,ADC_CHANNEL_7
}ADC_Channel;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Responsible for initializing the ADC driver.
 */
void ADC_init(const ADC_ConfigType* Config_Ptr);


/*
 * Description :
 * Responsible for reading analog data from an ADC channel
 * and converting it to a digital value using the ADC driver.
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
