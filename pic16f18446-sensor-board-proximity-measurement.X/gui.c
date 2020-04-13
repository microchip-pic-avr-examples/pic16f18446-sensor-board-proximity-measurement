/*
 * File:   gui.c
 * Author: M19219
 *
 * Created on December 6, 2017, 10:02 AM
 */

#include "gui.h"



void proximityScreenTasks() {

    //readBattery();
    //drawBatteryIcon(110, 1, 16, 8, 0xFF00);

    proximitySamples = 16;

    readProximity();

    //proximitySamples = 64;

    GFX_DrawText(0, 0, "Proximity", 0xFF00, 0x0000);

//    drawProximity(15, 15, 0xFF00);

    drawProximityPlots(64, 88, 0xFF00);
}


void proximityBuzzScreenStatic() {

    GFX_DrawText(0, 0, "Proximity", 0xFF00, 0x0000);
    GFX_DrawText(0, 15, "Buzz", 0xFF00, 0x0000);
}
