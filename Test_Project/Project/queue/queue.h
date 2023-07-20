/****************************************************************************************
* ALI SAHBAZ
*
* 
* LED Driver and Simple Queue Test with cppUtest TDD 
*
* Date          : 20.07.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com */
#ifndef __queue_H
#define __queue_H


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

typedef struct queue_str queue_str;

queue_str* queue_create(queue_data_types select_type , unsigned int size);
queue_out_types queue_data_write(queue_str * me , void* data , unsigned int data_size);
queue_out_types queue_data_read(queue_str * me , void* out_buffer, unsigned int out_buffer_size);
queue_data_types queue_get_type(queue_str * me);
unsigned int queue_get_size(queue_str * me);
queue_out_types queue_clear(queue_str * me);
  
#endif
