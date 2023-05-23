/*
 * File:   hal_gpio.c
 * Author: Mohamed Menazaa
 *
 * Created on May 12, 2023, 1:47 PM
 */


#include "hal_gpio.h"

/* Reference to the Data Direction Control Registers */
__IO uint8   *TRIS_REGESTERS[5] =   {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Registers */
__IO uint8   *LAT_REGESTERS[5]  =   {&LATA, &LATB, &LATC, &LATD, &LATE};
/* Reference to Port Registers */
__IO uint8   *PORT_REGESTERS[5] =   {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};



/**
 * 
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
                /* Set the LAT Register value to LOW as it initial value undetermined */
                CLR_BIT((*LAT_REGESTERS[_pin->port]), _pin->pin);  
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
STD_ReturnType gpio_pin_get_direction_status(pin_t *_pin){
    STD_ReturnType ret = E_OK;
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{
        _pin->direction = GET_BIT((*TRIS_REGESTERS[_pin->port]), _pin->pin);
    }    
    return ret;
}

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_write_logic(const pin_t *_pin){
    STD_ReturnType ret = E_OK;
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{
        switch(_pin->state){
            case GPIO_LOW:
                CLR_BIT((*LAT_REGESTERS[_pin->port]), _pin->pin);
            break;
            case GPIO_HIGH:
                SET_BIT((*LAT_REGESTERS[_pin->port]), _pin->pin);
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
STD_ReturnType gpio_pin_read_logic(pin_t *_pin){
    STD_ReturnType ret = E_OK;
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{
        _pin->state = GET_BIT((*PORT_REGESTERS[_pin->port]), _pin->pin);
    }    
    return ret;
}

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_toggle_logic(pin_t *_pin){
    STD_ReturnType ret = E_OK;
    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{
        _pin->state = TOG_BIT((*LAT_REGESTERS[_pin->port]), _pin->pin);
    }    
    return ret;
}



/**
 * 
 * @param _port
 * @param direction
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_direction_initialize(const port_index_t _port, uint8 direction){
    STD_ReturnType ret = E_OK;
    if(_port > MAXPORT_INDEX){
        ret = E_NOT_OK;
    }else{
        *TRIS_REGESTERS[_port]      =   direction;
        /* Set the LAT Register value to LOW as it initial value undetermined */
        *LAT_REGESTERS[_port]       =   STD_LOW;
    }    
    return ret;
}

/**
 * 
 * @param _port
 * @param direction
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_get_direction_status(const port_index_t _port, uint8* direction){
    STD_ReturnType ret = E_OK;
    if((_port > MAXPORT_INDEX) ||   (NULL == direction)){
        ret = E_NOT_OK;
    }else{
        *direction  = *TRIS_REGESTERS[_port];
    }    
    return ret;
}

/**
 * 
 * @param _port
 * @param logic
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_write_logic(const port_index_t _port, uint8 logic){
    STD_ReturnType ret = E_OK;
    if(_port > MAXPORT_INDEX){
        ret = E_NOT_OK;
    }else{
        *LAT_REGESTERS[_port]       =   logic;
    }    
    return ret;
}

/**
 * 
 * @param _port
 * @param logic
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_read_logic(const port_index_t _port, uint8* logic){
    STD_ReturnType ret = E_OK;
    if((_port > MAXPORT_INDEX) || (NULL == logic)){
        ret = E_NOT_OK;
    }else{
        *logic = *PORT_REGESTERS[_port];
    }    
    return ret;
}

/**
 * 
 * @param _port
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_toggle_logic(const port_index_t _port){
    STD_ReturnType ret = E_OK;
    if(_port > MAXPORT_INDEX){
        ret = E_NOT_OK;
    }else{
        *LAT_REGESTERS[_port]       =   *LAT_REGESTERS[_port] ^ PORT_MASK;
    }    
    return ret;
}
