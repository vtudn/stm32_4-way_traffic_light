# stm32_4-way_traffic_light

**SCENARIO**: Implementation of an embedded 4-way traffic light system with some specific functionalities, using the STM32F103C6 microcontroller. This work aims to practice some concepts such as embedded C programming, serial communication (SPI/I2C/UART), timer interrupt, co-operative scheduler, buttons/switches, ... Due to the lab's restraints, this project is only run for simulation.

**SOFTWARES**: STM32CubeIDE and Proteus.

**FUNCTIONALITIES**:

- The application has 12 LEDs including 4 red LEDs, 4 amber LEDs, 4 green LEDs.
- The application has 4 seven segment LEDs to display time with 2 for each road. The 2 seven segment LEDs will show time for each color LED corresponding to each road.
- The application has three buttons which are used
  - to select modes,
  - to modify the time for each color led on the fly, and
  - to set the chosen value.
- The application has at least 4 modes which is controlled by the first button. Mode 1 is a normal mode, while modes 2 3 4 are modification modes. You can press the first button to change the mode. Modes will change from 1 to 4 and back to 1 again.

*Mode 1 - Normal mode*:
  - The traffic light application is running normally.

*Mode 2 - Modify time duration for the red LEDs*: This mode allows you to change the time duration of the red LED in the main road. The expected behaviours of this mode include:
1. All single red LEDs are blinking in 2 Hz.
2. Use two seven-segment LEDs to display the value.
3. Use the other two seven-segment LEDs to display the mode.
4. The second button is used to increase the time duration value for the red LEDs.
5. The value of time duration is in a range of 1 - 99.
6. The third button is used to set the value.

*Mode 3 - Modify time duration for the amber LEDs*: Similar for the red LEDs described above with the amber LEDs.

*Mode 4 - Modify time duration for the green LEDs*: Similar for the red LEDs described above with the green LEDs.
