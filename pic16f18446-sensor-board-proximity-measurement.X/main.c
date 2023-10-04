 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "graphics.h"
#include "plot.h"
#include "ili9163c.h"
#include "backlight.h"
#include "proximity.h"
#include "gui.h"
#include "color.h"
#include "font.h"

/*
                         Main application
 */
#define MAX_SUPPORTED_MODE              (1)


volatile int8_t mode = 0;

volatile uint8_t s2Pressed = 0;
volatile uint8_t s3Pressed = 0;

extern FONT font8x12;


void onModeChanged(void)
{
    GFX_ClearScreen(0x0000);
  
    
    if ( (mode != 1) ) // if not proximity buzzer
    {
        proximityBuzzerDisable();       
        Timer2_Start(); // re-enable backlight dimming
    }
    

    switch(mode)
    {     
        case 0:
            // proximity
            initProximity();        
            break;
       
        case 1:
            // proximity buzz

            initProximity();         
            proximityBuzzScreenStatic();        
            proximityBuzzerEnable();
            
            Timer2_Stop(); // disable backlight dimming
            break;
     
            
        default:
            break;
    }
}




void onS2Action(void)
{
    if (S2_GetValue() == 0)
    {
        s2Pressed = 1;
        backlightTimerReset();
    }
}

void onS3Action(void)
{
    if (S3_GetValue() == 0)
    {
        s3Pressed = 1;
        backlightTimerReset();
    }
}


/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    proximityBuzzerDisable();
    backlightTimerInit(); // small LCD will fade out after BACKLIGHT_TIMER_MAX

    
    S2_SetInterruptHandler(onS2Action);
    S3_SetInterruptHandler(onS3Action);

    GFX_Initialize();
    GFX_SetFont(&font8x12);

    GFX_ClearScreen(0x0000);

    backlightFadeIn();

    onModeChanged();
   
    backlightAlwaysOn = 0;
   
    initProximity();

    while (1) {
    
        if(backlightIsOff()) {
            
            switch (mode)
            {

                case 0: // proximity screen
                    // turn ON if proximity sensor detects user
                    proximityTurnBacklightOn(); 
                    break;
                    
                default:
                    if (s2Pressed || s3Pressed) {
                        s2Pressed = 0;
                        s3Pressed = 0;
                        backlightFadeIn();
                        __delay_ms(250);
                    }
            }
 
        } else {
            
            if (s2Pressed)
            {
                mode--;
                if (mode < 0)
                {
                    mode = MAX_SUPPORTED_MODE;
                }
                onModeChanged();
                s2Pressed = 0;
            }

            if (s3Pressed)
            {
                mode++;
                if (mode > MAX_SUPPORTED_MODE)
                {
                    mode = 0;
                }
                onModeChanged();
                s3Pressed = 0;
            }
            
            
            switch (mode)
            {

                case 0:
                    // turn OFF small LCD if user is far away
                    proximityKeepBacklightOn();
                    // circle on small LCD, gauge on big LCD
                    proximityScreenTasks();
                    break;

                case 1:
                    // read proximity sensor and draw
                    // "proximity buzz" text on small LCD,
                    // gauge on big LCD
                    // + buzzer: variable pitch
                    proximityBuzz();
                    break;
                
                default:
                    break;
            }
        }
        
    }
}

/**
 End of File
*/