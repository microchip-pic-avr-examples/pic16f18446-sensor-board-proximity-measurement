<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Sensor Board Proximity Measurement

The PIC16F184xx family has a new Analog to Digital Converter with Computation (ADCC) with a 12-bit resolution. This project shows the reading of a proximity sensor using the ADCC. The sensor is made of a PCB trace on the board perimeter. The proximity sensor is used to detect human activity around the device. If no activity is detected for some time, the display backlight turns OFF, and turns back ON if the user approaches the hand.

In this example the PIC16F18446 Sensor Board is used. The demo has 2 operating modes:
1. A dynamic interpretation of the user’s hand distance to the sensor is displayed on the LCD;
2. The buzzer is generating a variable pitch tone, according to the user's hand distance. The PIC reads the proximity sensor, using the ADCC with Capacitive Voltage Division (CVD).

## Related Documentation
- [PIC16F18446 Product Family Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic16f18446)
- [PIC16F18446 datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40001985B.pdf) for more information or specifications.

## Software Used

- [MPLAB® X IDE](http://www.microchip.com/mplab/mplab-x-ide) v6.15 or newer
- [MPLAB® XC8](http://www.microchip.com/mplab/compilers) v2.45 or newer
- [MPLAB® Code Configurator (MCC)](microchip.com/mplab/mplab-code-configurator) v5.3.7
- [PIC16F1xxxx_DFP](https://packs.download.microchip.com/) v1.21.368

## Hardware Used

- [PIC16F18446 Sensor Board Demonstration](https://www.microchip.com/promo/pic16f18446-sensor-board-demonstration)
<br>

## Operation

To program the microcontroller with this MPLAB X project, follow the steps provided in the [How to Program the Microcontroller](#how-to-program-the-microcontroller) chapter.<br><br>

## Setup

The following configurations must be made for this project:

- Clock Control:
  - Clock Source: HFINTOSC
  - HF Internal Clock: 32 MHz
  - Clock Divider: 1

  <br><img src="images/clock_control.PNG" width="600">

- Configuration bits:
  - External Oscillator Selection: Oscillator not enabled
  - Reset Oscillator Selection: HFINTOSC (1MHz)

  <br><img src="images/config_bits.PNG" width="600">

- MSSP:
  - Serial Protocol: SPI
  - Mode: Host
  - SPI Mode: SPI Mode 0
  - Input Data Sampled At: Middle
  - Clock Source Selection: F<sub>OSC</sub>/4 

  <br><img src="images/mssp1.PNG" width="600">

- CLC:
  - Enable CLC: Yes
  - Operating Mode: AND-OR 

  <br><img src="images/clc1.PNG" width="600">
  <br><img src="images/clc2.PNG" width="600">

- FVR:
<br>FVR is used as positive refference for the ADCC, to get higher accuracy and gain.
  - Enable FVR: Yes
  - FVR buffer gain to ADC: 1x
  - FVR buffer gain to other peripherals: 1x

  <br><img src="images/fvr.PNG" width="600">

- ADCC:
  - Enable ADC: Yes
  - Operating Mode: Burst_average_mode
  - Result Alignment: Right
  - Positive Input Channel: ANA0
  - Positive Reference: FVR
  - Negative Reference: V<sub>SS</sub>
  - Auto-conversion Trigger: Disabled
  - Acquisition Count: 0
  - Clock Source: F<sub>OSC</sub>
  - Clock Divider: F<sub>OSC</sub>/128
  - Repeat: 64

  <br><img src="images/adcc_1.PNG" width="600">
  <br><img src="images/adcc_2.PNG" width="600">

- CCP1:
<br>CCP1 is used for generating the buzzer tone.
  - Enable CCP: Yes
  - CCP Mode: Compare
  - Select Timer: Timer 1
  - Mode: Toggle_cleartmr

  <br><img src="images/ccp1.PNG" width="600">

- CCP2:
<br>CCP2 is used for generating the PWM for the LCD Backlight.
  - Enable CCP: Yes
  - CCP Mode: PWM
  - Select Timer: Timer 2
  - Duty Cycle (%): 0
  - CCPR Alignment: right_aligned

  <br><img src="images/ccp2.PNG" width="600">

- CWG:
<br>CWG is used to output the signal from CCP1 in antiphase on 2 pins, so that the buzzer sounds louder.
  - Enable CWG: Yes
  - Input Source: CCP1_OUT
  - Output Mode: Half bridge mode
  - Clock Source: F<sub>OSC</sub>

  <br><img src="images/cwg1.PNG" width="600">

- TMR1:
<br>TMR1 is used to clock the CCP1. It sets the pitch of the buzzer tone.
  - Enable Timer: Yes
  - Clock Source: F<sub>OSC</sub>/4
  - Prescaler: 1:4
  - External Clock Input Sync: synchronize
  - Timer Period (s): 0.0327675

  <br><img src="images/tmr1.PNG" width="600">

- TMR2:
<br>TMR2 is used to clock the CCP2 for the LCD Backlight PWM, and also as a timebase for the proximity activity time measurement.
  - Enable Timer: Yes
  - Control Mode: Role over pulse
  - Start/Reset Option: Software control 
  - Clock Source: F<sub>OSC</sub>/4
  - Prescaler: 1:128
  - Postscaler: 1:8
  - Timer Period (s): 0.01
  - TMR Interrupt Enable: Yes

  <br><img src="images/tmr2.PNG" width="600">

- PIN_Grid
  <br><img src="images/pin_grid.PNG" width="600">

- PIN_Module
  <br><img src="images/pins.PNG" width="600">

## Demo

Board setup:

  <br><img src="images/demo.PNG" width="600">

## Summary

This code exemple shows the reading of a proximity sensor using the ADCC peripheral.

## How to Program the Microcontroller

This chapter demonstrates how to use the MPLAB X IDE to program a PIC® device with an `Example_Project.X`. This applies to other projects.

1.  Connect the Curiosity Development board to the PC.

2.  Open the `Example_Project.X` project in MPLAB X IDE.

3.  Set the `Example_Project.X` project as main project.
    <br>Right click the project in the **Projects** tab and then Set as Main Project.
    <br><img src="images/Program_Set_as_Main_Project.PNG" width="600">

4.  Clean and build the `Example_Project.X` project.
    <br>Right click the `Example_Project.X` project and select Clean and Build.
    <br><img src="images/Program_Clean_and_Build.PNG" width="600">

5.  Select Starter Kits (PKOB) in the Connected Hardware Tool section of the project settings:
    <br>Right click the project and **Properties**.
    <br>Click the arrow under the Connected Hardware Tool, and from the dropdown, select Starter Kits (PKOB) by clicking the SN.
    <br>Click **Apply** and then **OK**.
    <br><img src="images/Program_Tool_Selection.PNG" width="600">

6.  Program the project to the microcontroller.
    <br>Right click the project and then Make and Program Device.
    <br><img src="images/Program_Make_and_Program_Device.PNG" width="600">

<br>

- [Back to Top](#sensor-board-proximity-measurement)
- [Back to Setup](#setup)
- [Back to Demo](#demo)
- [Back to Summary](#summary)