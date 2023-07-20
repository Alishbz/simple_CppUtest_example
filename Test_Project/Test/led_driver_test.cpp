/****************************************************************************************
* ALI SAHBAZ
*
* 
* LED Driver and Simple Queue Test with cppUtest TDD 
*
* Date          : 20.07.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com */
#include "CppUTest/TestHarness.h"
#include "CppUtestExt/MockSupport_c.h"  
#include <string.h>
#include "led_driver.h"
#include "CppUTestExt/MockSupport.h"

#define MAX_LED_NUMBER 50

TEST_GROUP(led_driver_test_group)
{
  led_driver_str * LEDS[MAX_LED_NUMBER];
  int led_index = 0;
  
  void setup() {
    /** creates **/
    for(led_index = 0 ; led_index < MAX_LED_NUMBER ; led_index++){
      LEDS[led_index] = led_driver_create();
    }
  }
  
  void teardown() {
    /** destroys **/
    for(led_index = 0 ; led_index < MAX_LED_NUMBER ; led_index++){
       led_driver_destroy(LEDS[led_index] );
    }
  }
};

TEST(led_driver_test_group, led_create_test_1)
{
  led_driver_str *test_LED1;
   
  test_LED1 = led_driver_create();
  
  CHECK_EQUAL(LED_STATUS_NO_DIRECTION, led_driver_get_status( test_LED1 ) );
  CHECK_EQUAL(LED_ORDER_NO_DIRECTION, led_driver_get_order( test_LED1 ) );
  
  led_driver_destroy(test_LED1);
}

TEST(led_driver_test_group, led_create_test_2)
{
  for(led_index = 0 ; led_index < MAX_LED_NUMBER ; led_index++){
    CHECK_EQUAL(LED_STATUS_NO_DIRECTION, led_driver_get_status( LEDS[led_index] ) );
    CHECK_EQUAL(LED_ORDER_NO_DIRECTION, led_driver_get_order( LEDS[led_index] ) );
 }
}

TEST(led_driver_test_group, led_set_order_test_1)
{
  led_driver_set_order( LEDS[0] , LED_ORDER_OPEN);
  CHECK_EQUAL(LED_ORDER_OPEN, led_driver_get_order( LEDS[0] ) );
}


void tester(int x)
{
  mock().expectOneCall("testx").withParameter("addr", x);
}
