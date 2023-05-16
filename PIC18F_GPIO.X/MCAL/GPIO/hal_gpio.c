/*
 * File:   hal_gpio.c
 * Author: Mohamed Menazaa
 *
 * Created on May 12, 2023, 1:47 PM
 */


#include "hal_gpio.h"


uint8   *TRIS_REGESTERS[5] =   {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
uint8   *LAT_REGESTERS[5]  =   {&LATA, &LATB, &LATC, &LATD, &LATE};
uint8   *PORT_REGESTERS[5] =   {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};



STD_ReturnType gpio_pin_direction_initialize(const pin_t *_pin){
    
}
STD_ReturnType gpio_pin_get_direction_status(const pin_t *_pin){
    
}
STD_ReturnType gpio_pin_write_logic(const pin_t *_pin){
    
}
STD_ReturnType gpio_pin_read_logic(const pin_t *_pin){
    
}
STD_ReturnType gpio_pin_toggle_logic(const pin_t *_pin){
    
}




STD_ReturnType gpio_port_direction_initialize(const port_index_t *_port, uint8 direction){
    
}
STD_ReturnType gpio_port_get_direction_status(const port_index_t *_port, uint8* direction){
    
}
STD_ReturnType gpio_port_write_logic(const port_index_t *_port, uint8 logic){
    
}
STD_ReturnType gpio_port_read_logic(const port_index_t *_port, uint8* logic){
    
}
STD_ReturnType gpio_port_toggle_logic(const port_index_t *_port){
    
}
