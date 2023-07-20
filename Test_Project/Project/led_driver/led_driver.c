
#include "stdio.h"
#include <string.h> 
#include <stdlib.h>
#include "led_driver.h" 
/****************************************************************************************
* ALI SAHBAZ
*
* 
* LED Driver and Simple Queue Test with cppUtest TDD 
*
* Date          : 20.07.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com */
struct led_driver_str{
  led_status_estr status;
  led_order_estr order;
};

static void _led_driver_init(led_driver_str* me)
{
  me->status = LED_STATUS_NO_DIRECTION; 
  me->order = LED_ORDER_NO_DIRECTION;
}

led_driver_str* led_driver_create(void){  
  led_driver_str *me = (led_driver_str*)malloc(sizeof(led_driver_str));
  if(me != NULL){
    _led_driver_init(me);
  }
  return me;
}

void led_driver_destroy(led_driver_str* me)
{
  free(me);
}


led_status_estr led_driver_get_status(const led_driver_str* me)
{
  return me->status;
}


led_order_estr led_driver_get_order(const led_driver_str* me)
{
  return me->order;
}


void led_driver_set_order( led_driver_str* const me , led_order_estr order)
{
  if(order != LED_ORDER_NO_DIRECTION){
    me->order = order;
  }
}