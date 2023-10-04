/**
 * CLC2 Generated Driver File.
 * 
 * @file clc2.c
 * 
 * @ingroup  clc2
 * 
 * @brief This file contains the API implementations for the CLC2 driver.
 *
 * @version CLC2 Driver Version 1.1.0
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
#include "../clc2.h"


void CLC2_Initialize(void) 
{
    
    // LCG1POL not_inverted; LCG2POL not_inverted; LCG3POL inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLC2POL = 0x4;
    // LCD1S SDO from MSSP1; 
    CLC2SEL0 = 0x26;
    // LCD2S SDO from MSSP1; 
    CLC2SEL1 = 0x26;
    // LCD3S CCP3_OUT; 
    CLC2SEL2 = 0x16;
    // LCD4S CCP3_OUT; 
    CLC2SEL3 = 0x16;
    // LCG1D1N disabled; LCG1D1T enabled; LCG1D2N disabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLC2GLS0 = 0x2;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N disabled; LCG2D2T enabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLC2GLS1 = 0x8;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T disabled; LCG3D3N disabled; LCG3D3T enabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLC2GLS2 = 0x20;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T disabled; LCG4D4N disabled; LCG4D4T enabled; 
    CLC2GLS3 = 0x80;
    // LCMODE AND-OR; LCINTN disabled; LCINTP disabled; LCEN enabled; 
    CLC2CON = 0x80;

}

void CLC2_Enable(void) 
{
    CLC2CONbits.LC2EN = 1;
}

void CLC2_Disable(void) 
{
    CLC2CONbits.LC2EN = 0;
}


bool CLC2_OutputStatusGet(void) 
{
    return(CLC2CONbits.LC2OUT);
}
/**
 End of File
*/
