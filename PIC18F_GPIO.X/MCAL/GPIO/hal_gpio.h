
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
}logic_t;

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
    uint8 port:3;
    uint8 pin:3;
    uint8 direction:1;
    uint8 state:1;
}pin_t;
/* Section : Functions Declarations */


STD_ReturnType gpio_pin_direction_initialize(const pin_t *_pin);
STD_ReturnType gpio_pin_get_direction_status(const pin_t *_pin);
STD_ReturnType gpio_pin_write_logic(const pin_t *_pin);
STD_ReturnType gpio_pin_read_logic(const pin_t *_pin);
STD_ReturnType gpio_pin_toggle_logic(const pin_t *_pin);

STD_ReturnType gpio_port_direction_initialize(const port_index_t *_port, uint8 direction);
STD_ReturnType gpio_port_get_direction_status(const port_index_t *_port, uint8* direction);
STD_ReturnType gpio_port_write_logic(const port_index_t *_port, uint8 logic);
STD_ReturnType gpio_port_read_logic(const port_index_t *_port, uint8* logic);
STD_ReturnType gpio_port_toggle_logic(const port_index_t *_port);





#endif	/* HAL_GPIO_H */

