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
#include "queue.h"
#include "CppUTestExt/MockSupport.h"

/*
typedef enum{
  SUCCESS_Q,
  ERROR_Q,
  TIMEOUT_Q, 
  TRUE_Q,
  FALSE_Q
}queue_out_types;

typedef enum{
  INT_Q,
  SHORT_Q,
  CHAR_Q,
  DOUBLE_Q,
  UINT_Q,
  USHORT_Q,
  UCHAR_Q,   
}queue_data_types;

queue_str* queue_create(queue_data_types select_type , unsigned int size);
queue_out_types queue_data_write(queue_str * me , void* data , unsigned int data_size);
queue_out_types queue_data_read(queue_str * me , void* out_buffer, unsigned int out_buffer_size);
queue_data_types queue_get_type(queue_str * me);
unsigned int queue_get_size(queue_str * me);
queue_out_types queue_clear(queue_str * me);
*/

TEST_GROUP(queue_group)
{
  void setup() {
  }
  
  void teardown() {
  }
};

TEST(queue_group, queue_create_test)
{
   queue_str *_q = queue_create(SHORT_Q , 50);
   if(_q == NULL){ FAIL("queue create fail"); }
   CHECK_EQUAL(SHORT_Q, queue_get_type( _q ) );
   CHECK_EQUAL(50, queue_get_size( _q ) );
   queue_clear(_q);
}

TEST(queue_group, queue_memory_leak_test)
{
   queue_str *_q = queue_create(CHAR_Q , 4);
   if(_q == NULL){ FAIL("queue create fail"); }
   CHECK_EQUAL(CHAR_Q, queue_get_type( _q ) );
   CHECK_EQUAL(4, queue_get_size( _q ) );
   
   char write_buf[5] = { 8 , 9 , 7 , 6 , 1}; 
   char read_buf[5];
   CHECK_EQUAL(SUCCESS_Q , queue_data_write( _q , (void*)write_buf, 3));
   CHECK_EQUAL(SUCCESS_Q , queue_data_read( _q , (void*)read_buf, 3));
  
  CHECK_EQUAL(8, read_buf[0] );
  CHECK_EQUAL(9, read_buf[1] );
  CHECK_EQUAL(7, read_buf[2] );
  CHECK_EQUAL(6, read_buf[3] );
  CHECK_EQUAL(1, read_buf[4] );
            
   queue_clear(_q);
}

TEST(queue_group, queue_write_test)
{

}

TEST(queue_group, queue_read_test)
{

}

TEST(queue_group, queue_clear_test)
{

}

TEST(queue_group, queue_is_empty_test)
{

}

