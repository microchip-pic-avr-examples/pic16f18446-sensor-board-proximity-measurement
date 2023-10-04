/**
 * CWG1 Generated Driver File.
 * 
 * @file cwg1.c
 * 
 * @ingroup  cwg1
 * 
 * @brief This file contains the API implementations for the CWG1 driver.
 *
 * @version CWG1 Driver Version 2.11.1
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

#include <xc.h>
#include "../cwg1.h"

void CWG1_Initialize(void) {
    // CWGCS FOSC; 
    CWG1CLKCON = 0x0;
    // CWGPOLA non inverted; CWGPOLB non inverted; CWGPOLC non inverted; CWGPOLD non inverted; 
    CWG1CON1 = 0x0;
    // CWGDBR 0; 
    CWG1DBR = 0x0;
    // CWGDBF 0; 
    CWG1DBF = 0x0;
    // CWGSHUTDOWN No Auto-shutdown; CWGREN disabled; CWGLSBD tri-stated; CWGLSAC tri-stated; 
    CWG1AS0 = 0x14;
    // AS0E disabled; AS1E disabled; AS2E disabled; AS3E disabled; AS4E disabled; AS5E disabled; AS6E disabled; 
    CWG1AS1 = 0x0;
    // CWGOVRD low; CWGOVRC low; CWGOVRB low; CWGOVRA low; CWGSTRD disabled; CWGSTRC disabled; CWGSTRB disabled; CWGSTRA disabled; 
    CWG1STR = 0x0;
    // CWGIS CCP1_OUT; 
    CWG1ISM = 0x1;
    /*CWGEN enabled; CWGMODE Half bridge mode; CWGLD Buffer_not_loaded; */
    CWG1CON0 = 0x84;
    
}

void CWG1_LoadRiseDeadbandCount(uint8_t dutyValue)
{
     CWG1DBR = dutyValue;
}

void CWG1_LoadFallDeadbandCount(uint8_t dutyValue)
{
     CWG1DBF = dutyValue;
}

void CWG1_LoadBufferEnable(void)
{
     CWG1CON0bits.CWG1LD = 0;
}

bool CWG1_IsModuleEnabled(void)
{
   return (CWG1CON0bits.CWG1EN);
}

void CWG1_AutoShutdownEventSet(void)
{
    CWG1AS0bits.CWG1SHUTDOWN =1;
}

void CWG1_AutoShutdownEventClear(void)
{
    CWG1AS0bits.CWG1SHUTDOWN =0;
}

