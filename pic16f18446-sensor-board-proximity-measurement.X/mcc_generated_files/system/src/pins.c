/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.0.0
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

#include "../pins.h"

void (*S2_InterruptHandler)(void);
void (*S3_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0x39;
    TRISB = 0x70;
    TRISC = 0x19;

    /**
    ANSELx registers
    */
    ANSELA = 0x31;
    ANSELB = 0x40;
    ANSELC = 0x6D;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
  
    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONB = 0xF0;
    SLRCONC = 0xFF;
    /**
    INLVLx registers
    */
    INLVLA = 0x3F;
    INLVLB = 0xF0;
    INLVLC = 0xFF;

    /**
    PPS registers
    */
    SSP1DATPPS = 0xC; //RB4->MSSP1:SDI1;
    RC5PPS = 0x02;  //RC5->CLC2:CLC2OUT;
    RC6PPS = 0x01;  //RC6->CLC1:CLC1OUT;
    RA1PPS = 0x05;  //RA1->CWG1:CWG1A;
    RA2PPS = 0x06;  //RA2->CWG1:CWG1B;
    SSP1CLKPPS = 0x11;  //RC1->MSSP1:SCK1;
    RC1PPS = 0x13;  //RC1->MSSP1:SCK1;
    CCP2PPS = 0x12;  //RC2->CCP2:CCP2;
    RC2PPS = 0x0A;  //RC2->CCP2:CCP2;

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x20;
    IOCBN = 0x20;
    IOCBF = 0x0;
    IOCCP = 0x10;
    IOCCN = 0x10;
    IOCCF = 0x0;

    S2_SetInterruptHandler(S2_DefaultInterruptHandler);
    S3_SetInterruptHandler(S3_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin S2}
    if(IOCBFbits.IOCBF5 == 1)
    {
        S2_ISR();  
    }
    // interrupt on change for pin S3}
    if(IOCCFbits.IOCCF4 == 1)
    {
        S3_ISR();  
    }
}
   
/**
   S2 Interrupt Service Routine
*/
void S2_ISR(void) {

    // Add custom IOCBF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(S2_InterruptHandler)
    {
        S2_InterruptHandler();
    }
    IOCBFbits.IOCBF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF5 at application runtime
*/
void S2_SetInterruptHandler(void (* InterruptHandler)(void)){
    S2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF5
*/
void S2_DefaultInterruptHandler(void){
    // add your S2 interrupt custom code
    // or set custom function using S2_SetInterruptHandler()
}
   
/**
   S3 Interrupt Service Routine
*/
void S3_ISR(void) {

    // Add custom IOCCF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(S3_InterruptHandler)
    {
        S3_InterruptHandler();
    }
    IOCCFbits.IOCCF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF4 at application runtime
*/
void S3_SetInterruptHandler(void (* InterruptHandler)(void)){
    S3_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF4
*/
void S3_DefaultInterruptHandler(void){
    // add your S3 interrupt custom code
    // or set custom function using S3_SetInterruptHandler()
}
/**
 End of File
*/