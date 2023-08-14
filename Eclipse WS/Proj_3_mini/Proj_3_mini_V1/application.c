/*
 * application.c
 *
 *  Created on: May 7, 2023
 *      Author: Hesham
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

//To indicate the state of the "fan" shown on the LCD
typedef enum{
	OFF,ON
}APP_fanState;

int main(){

	uint8 LM35_temperature = 0;

	//Configuration of the adc driver
	ADC_ConfigType ADC_app = {ADC_INTERNAL_2V56,ADC_F_CPU_8};

	//Initial value for the "fan_1" variable that gets changed later in runtime
	APP_fanState fan_1 = OFF;

	//Drivers initialization
	ADC_init(&ADC_app);
	LCD_init();
	DCMotor_Init();

	//LCD characters that are shown once and never change in runtime
	LCD_displayStringRowColumn(0, 4, "Fan is ");
	LCD_displayStringRowColumn(1, 4, "Temp = "); // hnktb f 12
	LCD_displayStringRowColumn(1, 13, "  c");


	for(;;){

		LM35_temperature=LM35_getTemperature();

		//fan state is ON by default and is changed to OFF only if temp<30
		fan_1 = ON;

		if(LM35_temperature<30){
			//Stop the motor
			DCMotor_Rotate(DC_MOTOR_STOP, 0);

			//to show that fan is off on LCD
			fan_1 = OFF;
		}
		else if( (LM35_temperature>=30) && (LM35_temperature<60) ){
			DCMotor_Rotate(DC_MOTOR_CW, 25);
		}
		else if( (LM35_temperature>=60) && (LM35_temperature<90) ){
			DCMotor_Rotate(DC_MOTOR_CW, 50);
		}
		else if( (LM35_temperature>=90) && (LM35_temperature<120) ){
			DCMotor_Rotate(DC_MOTOR_CW, 75);
		}
		else{
			DCMotor_Rotate(DC_MOTOR_CW, 100);
		}

		//show the new temperature on LCD
		LCD_moveCursor(1, 11);
		LCD_intgerToString(LM35_temperature);
		LCD_displayCharacter(' ');

		/*show the new fan state on LCD
		if fan_1 is on display "ON" otherwise display "OFF"*/
		LCD_moveCursor(0, 11);
		(fan_1)? LCD_displayString("ON ") : LCD_displayString("OFF");
	}
}
