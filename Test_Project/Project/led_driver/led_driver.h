/****************************************************************************************
* ALI SAHBAZ
*
* 
* LED Driver and Simple Queue Test with cppUtest TDD 
*
* Date          : 20.07.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com */
#ifndef __led_driver_H
#define __led_driver_H

#include "stdint.h" 

typedef enum {
    LED_STATUS_NO_DIRECTION = 0,
    LED_STATUS_OPEN,
    LED_STATUS_CLOSE
} led_status_estr;

typedef enum {
    LED_ORDER_NO_DIRECTION = 0,
    LED_ORDER_OPEN,
    LED_ORDER_CLOSE
} led_order_estr;

/** private struct **/
typedef struct led_driver_str led_driver_str;

led_driver_str* led_driver_create(void);
void            led_driver_destroy(led_driver_str* me);
led_status_estr led_driver_get_status(const led_driver_str* me);
led_order_estr  led_driver_get_order(const led_driver_str* me);
void            led_driver_set_order( led_driver_str* const me , led_order_estr order);

#endif
