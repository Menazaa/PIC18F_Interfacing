
/*
 * File:   hal_gpio.h
 * Author: Mohamed Menazaa
 *
 * Created on May 12, 2023, 1:47 PM
 */

  
#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/* Section : Includes */

#include "../compiler.h"
#include "../mcal_std_types.h"
#include "../device_config.h"

/* Section : Macros Declarations */

/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
typedef enum{
    GPIO_LOW,
    GPIO_HIGH
}gpio_logic_t;

typedef enum{
    GPIO_OUTPUT,
    GPIO_INPUT
}direction_t;


typedef enum{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;


typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef struct{
    uint8 port:3;       /* @ref port_index_t */
    uint8 pin:3;        /* @ref pin_index_t */
    uint8 direction:1;  /* @ref direction_t */
    uint8 state:1;      /* @ref gpio_logic_t */
}pin_t;


/* Section : Functions Declarations */



/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_direction_initialize(const pin_t *_pin);

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_get_direction_status(const pin_t *_pin);

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_write_logic(const pin_t *_pin);

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_read_logic(const pin_t *_pin);

/**
 * 
 * @param _pin
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_pin_toggle_logic(const pin_t *_pin);

/**
 * 
 * @param _port
 * @param direction
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_direction_initialize(const port_index_t *_port, uint8 direction);

/**
 * 
 * @param _port
 * @param direction
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_get_direction_status(const port_index_t *_port, uint8* direction);

/**
 * 
 * @param _port
 * @param logic
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_write_logic(const port_index_t *_port, uint8 logic);

/**
 * 
 * @param _port
 * @param logic
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_read_logic(const port_index_t *_port, uint8* logic);

/**
 * 
 * @param _port
 * @return STD_ReturnType (E_OK or E_NOT_OK)
 */
STD_ReturnType gpio_port_toggle_logic(const port_index_t *_port);





#endif	/* HAL_GPIO_H */

