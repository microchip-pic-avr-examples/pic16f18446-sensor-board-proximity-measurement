/*
 * File:   backlight.c
 * Author: M19219
 *
 * Created on November 21, 2017, 9:37 AM
 */

#include "backlight.h"
#include "stdint.h"
#include "mcc_generated_files/mcc.h"


#define BACKLIGHT_TIMER_MAX 1000 // 5s

uint8_t backlightPWM = 0;
uint16_t backlightTimer;
//uint8_t brt;
//uint8_t oldBrt;

uint8_t backlightAlwaysOn;


void backlightSet(uint8_t pwm) {
    PWM2_LoadDutyValue(pwm*1.22);
    /*brt = (pwm >> 4) & 0x0F;
    if(brt != oldBrt) {
        EUSART1_Puts("brt ");
        EUSART1_Putn(brt);
        EUSART1_Puts("\n");
        oldBrt = brt;
    }*/ // big LCD always ON
}


void backlightFadeIn() {
    while(backlightPWM<255) {
        backlightPWM++;
        backlightSet(backlightPWM);
        __delay_ms(1);
    }
}


void backlightFadeOut() {
    while(backlightPWM>0) {
        backlightPWM--;
        backlightSet(backlightPWM);
        __delay_ms(1);
    }
}


void tick10ms() {
    if(!backlightAlwaysOn) {
        if(backlightTimer < BACKLIGHT_TIMER_MAX) {
            backlightTimer++;
            if(backlightTimer == BACKLIGHT_TIMER_MAX) {
                backlightFadeOut();
            }
        } 
    }
}



void backlightTimerInit() {   
    backlightTimer = 0;
    TMR2_SetInterruptHandler(tick10ms);   
}



void backlightTimerReset() {
    backlightTimer = 0;
}



uint8_t backlightIsOff() {
    return (backlightPWM == 0);
}