# Fan Speed Controller Embedded System - ATmega32

This project implements a temperature-controlled fan using the ATmega32 microcontroller. The fan's speed is automatically adjusted based on the temperature sensed by the LM35 temperature sensor. The ATmega32 microcontroller operates at a frequency of 1MHz.




## Table of Contents

- [Requirements](#requirements)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Usage](#usage)

---
## Requirements

### Temperature Sensing and Display

- The LM35 temperature sensor provides continuous analog output, converted to digital values using the ADC.
- Calculations in the microcontroller convert digital values to temperature readings.
- The temperature value is displayed on an 8-bit data mode LCD.

### Fan Control Logic

The microcontroller monitors the temperature and controls the fan as follows:

- If temperature < 30°C: Fan off.
- If 30°C <= temperature < 60°C: Fan at 25% speed.
- If 60°C <= temperature < 90°C: Fan at 50% speed.
- If 90°C <= temperature < 120°C: Fan at 75% speed.
- If temperature >= 120°C: Fan at 100% speed.

### Layered Architecture

The project follows a layered architecture model, incorporating the following components:

- ADC Driver
- GPIO Driver
- LCD Driver (8-bit data mode)
- Temperature Sensor Driver
- DC-Motor Driver
- PWM Driver (using Timer0)

![image](https://github.com/Hesham-Hesham/Fan-Speed-Controller-Embedded-System-ATmega32/assets/91581641/617b47b9-ae6f-4560-bed0-b69452b82517)




For the full detailed drivers' requirements check [The Project requirements file](https://github.com/Hesham-Hesham/Fan-Speed-Controller-Embedded-System-ATmega32/blob/main/System%20Requirements.pdf)

---

## Components

1. **ATmega32 Microcontroller:** The main processing unit that controls the entire system.

2. **LM35 Temperature Sensor:** A sensor that provides analog temperature readings.

3. **LCD Display:** An 8-bit data mode LCD to display the temperature and fan state.

4. **DC Motor:** The fan motor whose speed will be controlled based on the temperature.

5. **Motor Driver Circuit:** A motor driver circuit to control the direction and speed of the DC motor.

6. **Power Supply:** A suitable power supply for the microcontroller, motor, and other components.

7. **Oscilloscope:** To graphically display the varying duty cycle 



---

## Circuit Diagram

![image](https://github.com/Hesham-Hesham/Fan-Speed-Controller-Embedded-System-ATmega32/assets/91581641/306d14f4-f82b-4e66-8086-94db5c0e1b01)



---

## Usage
- ### Hardware target
    In order to run the code on a real hardware target (ARmega32), follow these steps:
1. **Setup**: Connect the components as per the circuit diagram.
2. **Compile**: Use an appropriate compiler (e.g., AVR GCC) to compile the provided source code.
3. **Program**: Program the ATmega32 Microcontroller with the compiled binary using a suitable programmer (e.g., AVR ISP).
4. **Run**: Power up the circuit. The Stopwatch will start counting immediately.
5. **User Interaction**: Use the push buttons as follows:
   - The speed of the fan is controlled by the temperature the sensor reads.



- ### Simulation
1.  **Setup**: Install proteus 8 professional v10.0 or higher
2. **Install Add-ons**: Add the necessary arduino and avr add-ons (Arduino_Proteus_Libraries)
3. **Run**: Run the .pdsprj file in the /Proteus Simulation folder in any of the versions 

<br/><br/>

---

This project was made during the Full Embedded Systems Diploma under the supervision of Engineer Mohamed Tarek.

---

*Note: This README provides an overview of the project and its requirements. For detailed implementation and code, please refer to the source files provided in this repository.*
