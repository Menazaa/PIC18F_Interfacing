/* 
 * File:   Application.c
 * Author: Mohamed Menazaa
 *
 * Created on May 12, 2023, 11:40 AM
 */

#include "Application.h"

#define _XTAL_FREQ   4000000UL

/*
 * 
 */
int main(void) {
    gpio_port_direction_initialize(PORTC_INDEX, GPIO_OUTPUT);
    while(STD_ON){
        gpio_port_toggle_logic(PORTC_INDEX);
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

