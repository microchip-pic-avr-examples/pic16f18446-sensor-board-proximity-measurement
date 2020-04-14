<div id="readme" class="Box-body readme blob js-code-block-container">
  <article class="markdown-body entry-content p-3 p-md-6" itemprop="text"><p><a href="https://www.microchip.com" rel="nofollow"><img src="https://camo.githubusercontent.com/5fb5505f69a28ff407841612dfe2b7004f210594/68747470733a2f2f636c6475702e636f6d2f553071684c7742696a462e706e67" alt="MCHP" data-canonical-src="https://cldup.com/U0qhLwBijF.png" style="max-width:100%;"></a></p>


# Introduction
The PIC16F184xx family has a new Analog to Digital Converter with Computation (ADCC) with a 12-bit resolution. This project shows the reading of a proximity sensor using the ADCC. The sensor is made of a PCB trace on the board perimeter. The proximity sensor is used to detect human activity around the device. If no activity is detected for some time, the display backlight turns OFF, and turns back ON if the user approaches the hand.

# Description
In this example we will be using the PIC16F18446 Sensor Board. The demo has 2 operating modes: In the first mode, a dynamic interpretation of the user’s hand distance to the sensor is displayed on the LCD, and in the second mode, the buzzer is generating a variable pitch tone, according to the user's hand distance. The PIC reads the proximity sensor, using the ADCC with Capacitive Voltage Division (CVD).

# MCC Settings
Here are the settings used for MSSP, CLC, FVR, ADCC, CCP, CWG, TMR1 and TMR2. MSSP + CLC are used for the LCD control.

### MSSP Settings

![MSSP Settings](images/MSSP1.png)

### CCL Settings

![CCL1 Settings](images/CLC1.png)

![CCL2 Settings](images/CLC2.png)

### FVR Settings
FVR is used as positive refference for the ADCC, to get higher accuracy and gain.

![FVR Settings](images/FVR.png)

### ADCC settings

![ADCC Settings](images/ADCC1.png)

ADRPT register is set to 0x40, to average a burst of 64 samples.

![ADCC Registers](images/ADCC2.png)

### CCP Settings
CCP1 is used for generating the buzzer tone.

![CCP Settings](images/CCP1.png)

CCP2 is used for generating the PWM for the LCD Backlight.

![CCP Settings](images/CCP1.png)

### CWG Settings
CWG is used to output the signal from CCP1 in antiphase on 2 pins, so that the buzzer sounds louder.

![CWG Settings](images/CWG1.png)

### TMR Settings
TMR1 is used to clock the CCP1. It sets the pitch of the buzzer tone.

![TMR Settings](images/TMR1.png)

TMR2 is used to clock the CCP2 for the LCD Backlight PWM, and also as a timebase for the proximity activity time measurement.

![TMR Settings](images/TMR2.png)

### PIN Grid

![PIN Grid](images/PIN_Grid.png)

### PIN Module

![PIN Module](images/PIN_Module.png)
