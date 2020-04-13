/*
 * File:   eusart_util.c
 * Author: M19219
 *
 * Created on January 10, 2018, 3:54 PM
 */


#include "eusart_util.h"

void EUSART1_Puts(uint8_t *str) {
    uint8_t i = 0;
    
    while(str[i] != 0) {
        EUSART1_Write(str[i]);
        i++;
    }
}

void EUSART1_Putn(int16_t n) {
    
    if(n<0) {
        EUSART1_Write('-');
        n = -n;
    }
    
    EUSART1_Write( ((n/10000)%10) + '0' );
    EUSART1_Write( ((n/1000)%10) + '0' );
    EUSART1_Write( ((n/100)%10) + '0' );
    EUSART1_Write( ((n/10)%10) + '0' );
    EUSART1_Write( ((n)%10) + '0' );
}