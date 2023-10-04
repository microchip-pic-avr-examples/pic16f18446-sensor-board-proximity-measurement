/*
 * File:   proximity.c
 * Author: M19219
 *
 * Created on November 21, 2017, 9:56 AM
 */

#include <stdio.h>
#include <stdbool.h>

#include "mcc_generated_files/system/system.h"
#include "graphics.h"
#include "plot.h"
#include "proximity.h"
#include "backlight.h"


static volatile uint32_t proximityMin;
static volatile uint32_t proximityMax;
static volatile uint32_t proximityTh;
uint32_t proximity10bit, proximity12bit;
uint32_t proximity10bitOffset, proximity12bitOffset;

bool objectDetected = false;

uint16_t proximitySamples;

const uint16_t proximitySamplesReleased = 64;
const uint16_t proximitySamplesDetected = 16;
const uint16_t proximitySamplesBuzz = 32;
const uint16_t proximitySamplesDemo = 32;

volatile uint16_t proximityTimeCounter;


void proximityTick10ms(void)
{
    if (proximityTimeCounter < 0xFFFF)
    {
        proximityTimeCounter++;
    }
}


void readProximity(void)
{   
    uint32_t res = 0;
    
    ADREF = 0x00; // ADNREF VSS; ADPREF VDD
    
    ADPRE = 50; // max 8191
    ADCON1bits.ADPPOL = 0; // to VDD
    
    ADACQ = 25; // max 8191
    
    for (uint16_t i = 0; i < proximitySamples; i++)
    {
        ADCC_GetSingleConversion(channel_Proximity);
        res += ADCC_GetAccumulatorValue() >> 6;
    }
        
    res = res / (proximitySamples>>2);
    
    ADPRE = 0;
    ADACQ = 0;
    
    if ( proximityMin > res )
    {
        proximityMin = res;
    }
    
    if ( proximityMax < res )
    {
        proximityMax = res;
        proximityTh = proximityMax;
    }
    
    proximity12bit = res;
    proximity10bit = res & 0xFFFFFFFC;
}



void proximityTurnBacklightOn(void) {
    readProximity();
    
    if ((proximity12bit+10) < proximityTh) {          
        objectDetected = true;
        proximityTh -= 10;       
        proximitySamples = proximitySamplesDetected;
        backlightFadeIn();
        backlightTimerReset();
    }
}





void proximityKeepBacklightOn() {   
    readProximity();
    
    if ((proximity12bit+10) < proximityTh) {          
        proximityTh -= 10;       
        backlightTimerReset();
    }    
}





void initProximity(void)
{
    proximityMin = 0xFFFF;
    proximityMax = 0;
    proximityTh = 0;
    
    proximitySamples = 64;//4096;
    
    clearPlot(&plot1, 0);
    clearPlot(&plot2, 0);
    
    readProximity();
    
    proximity10bitOffset = proximity10bit;
    proximity12bitOffset = proximity12bit;
    
    objectDetected = false;
}



void drawProximity(uint8_t x, uint8_t y, uint16_t color)
{
    char buff[20];

    sprintf(buff,"%lu / %lu", proximity12bit, proximityMax);
    GFX_DrawText(x, y, buff, color, 0x0000); 
}


void drawProximityPlots(uint8_t x, uint8_t y, uint16_t color)
{
    int16_t v, v2; 
    static int16_t oldV = 0;
    
    v2 = (proximityMax - proximity12bit);
    
    if (v2 < 0)
    {
        v2 = 0;
    }
    else
    {
        if (v2 > 100)
        {
            v2 = 100;
        }
    }
    
    v = v2;
    
    // 0 to 100
    
    v *= 58;
    v /= 100;
    
    // 0 to 58
    
    v += 5;
    
    
    if (oldV != v)
    {
        GFX_DrawCircle(x, y, oldV, 0x0000);
        GFX_DrawCircle(x, y, v, color);
    }
    
    oldV = v;
    
}

void proximityBuzzerEnable(void)
{
    //PIE6bits.CCP1IE = 1;
    proximitySamples = proximitySamplesBuzz;
    BUZZ_P_TRIS = 0;
    BUZZ_N_TRIS = 0;
}

void proximityBuzzerDisable(void)
{
    //PIE6bits.CCP1IE = 0;
    if(objectDetected)
    {
        proximitySamples = proximitySamplesDetected;
    } else {
        proximitySamples = proximitySamplesReleased;
    }
    BUZZ_P_TRIS = 1;
    BUZZ_N_TRIS = 1;
}

void proximityBuzz(void)
{
    
    readProximity();
    
    int16_t a = 50 + proximityMax - proximity12bit;
    
    if (a < 0)
    {
        a = 0;
    }

    if (a > 199)
    {
        a = 199;
    }
    
    a = 200 - a;
    
    a *= 15;
    
    if (a == 3000)
    {
        a = 0x7FFF;
    }
    
    CCP1_SetCompareCount(a);
}