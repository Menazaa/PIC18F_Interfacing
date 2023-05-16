/*
 * File:   hal_gpio.c
 * Author: Mohamed Menazaa
 *
 * Created on May 12, 2023, 1:47 PM
 */


#include "hal_gpio.h"

/* Reference to the Data Direction Control Registers */
uint8   *TRIS_REGESTERS[5] =   {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Registers */
uint8   *LAT_REGESTERS[5]  =   {&LATA, &LATB, &LATC, &LATD, &LATE};
/* Reference to Port Registers */
uint8   *PORT_REGESTERS[5] =   {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
STD_ReturnType ret = E_OK;


/**
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_direction_initialize(const pin_t *_pin){
    STD_ReturnType ret = E_OK;
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{
        switch(_pin->direction){
            case GPIO_OUTPUT:
                CLR_BIT((*TRIS_REGESTERS[_pin->port]), _pin->pin);
            break;
            case GPIO_INPUT:
                SET_BIT((*TRIS_REGESTERS[_pin->port]), _pin->pin);
            break;
            default: ret = E_NOT_OK;
        }
    }    
    return ret;
}

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_get_direction_status(const pin_t *_pin){
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{

    }    
    return ret;
}

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_write_logic(const pin_t *_pin){
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{

    }    
    return ret;
}

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_read_logic(const pin_t *_pin){
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{

    }    
    return ret;
}

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_toggle_logic(const pin_t *_pin){
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{

    }    
    return ret;
}



/**
 * 
 * @param _port
 * @param direction
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_direction_initialize(const port_index_t *_port, uint8 direction){
    
}

/**
 * 
 * @param _port
 * @param direction
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_get_direction_status(const port_index_t *_port, uint8* direction){
    
}

/**
 * 
 * @param _port
 * @param logic
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_write_logic(const port_index_t *_port, uint8 logic){
    
}

/**
 * 
 * @param _port
 * @param logic
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_read_logic(const port_index_t *_port, uint8* logic){
    
}

/**
 * 
 * @param _port
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_toggle_logic(const port_index_t *_port){
    
}
