/**
 * CWG1 Generated Driver API Header File.
 * 
 * @file cwg1.h
 * 
 * @defgroup  cwg1 CWG1
 * 
 * @brief This file contains the API prototypes for the CWG1 driver.
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


#ifndef CWG1_H
 #define CWG1_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @ingroup cwg1
 * @brief  Initializes the CWG1 module. This is called only once before calling other CWG1 APIs.
 * @param None.
 * @return None.
 * 
 */
void CWG1_Initialize(void);


/**
 * @ingroup cwg1
 * @brief  Sets the duration of the dead-band interval on the rising edge of the input source signal.
 * @pre CWG1_Initialize() is already called.
 * @param dutyValue - Duty cycle value.
 * @return None.
 * 
 */
void CWG1_LoadRiseDeadbandCount(uint8_t dutyValue);

/**
 * @ingroup cwg1
 * @brief  Sets the duration of the dead-band interval on the falling edge of the input source signal.
 * @pre CWG1_Initialize() is already called.
 * @param dutyValue - Duty cycle value.
 * @return None.
 * 
 */
void CWG1_LoadFallDeadbandCount(uint8_t dutyValue);

/**
 * @ingroup cwg1
 * @brief Enables the CWG1 module to load the buffers on the next rising or falling event of the input signal.
 * @pre CWG1_Initialize() is already called.
 * @param None.
 * @return None.
 */
void CWG1_LoadBufferEnable(void);

/**
 * @ingroup cwg1
 * @brief Returns the status of the CWG1 module.
 * @param None.
 * @retval True - CWG1 is enabled.
 * @retval False - CWG1 is disabled.
 * 
 */
bool CWG1_IsModuleEnabled(void);

/**
 * @ingroup cwg1
 * @brief Puts the CWG outputs into the Auto-Shutdown state.
 * @pre CWG1_Initialize() is already called.
 * @param None.
 * @return None.
 */
void CWG1_AutoShutdownEventSet(void);

/**
 * @ingroup cwg1
 * @brief Resumes the operation of the CWG when the Auto-Shutdown state is disabled.
 * @pre  CWG1_Initialize() and CWG1_AutoShutdownEventSet() are already called.
 * @param None.
 * @return None.
 * 
 */
void CWG1_AutoShutdownEventClear(void);


#endif  // CWG1_H
