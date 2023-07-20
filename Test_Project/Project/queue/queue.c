/****************************************************************************************
* ALI SAHBAZ
*
* 
* LED Driver and Simple Queue Test with cppUtest TDD 
*
* Date          : 20.07.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com */
#include "stdio.h"
#include <string.h> 
#include <stdlib.h>
#include "queue.h" 
 
  
typedef union {
  int data_i;
  short data_s;
  char data_c;
  double data_d;
  unsigned int data_ui;
  unsigned short data_us;
  unsigned char data_uc;
}var;

/** private queue struct **/
struct queue_str{
  
    queue_data_types type;
      
    unsigned int read_ptr;
    
    unsigned int write_ptr;
    
    unsigned int data_buffer_size;
     
    var * data_buffer; 
    
};



queue_str* queue_create(queue_data_types select_type , unsigned int size){  

  queue_str *me = (queue_str*)malloc(sizeof(queue_str));
  
  me->read_ptr  = 0;
  
  me->write_ptr = 0;
  
  me->data_buffer_size = size;
  
  me->type = select_type;
    
  me->data_buffer = (var*)malloc(sizeof(var)*size);  

  return me;
}


static void check_write_ptr(queue_str * me){

  if(me->write_ptr > me->data_buffer_size){
     me->write_ptr = 0;
  }
}


static void check_read_ptr(queue_str * me){

  if(me->read_ptr > me->data_buffer_size){
     me->read_ptr = 0;
  }
}

/** true-> queue empty , false -> queue not empty **/
queue_out_types queue_is_empty(queue_str * me){
  if( me->read_ptr == me->write_ptr ){
     return TRUE_Q;
  }
  return FALSE_Q;
}

queue_out_types queue_clear(queue_str * me){
  free(me->data_buffer);
  free(me);
  return SUCCESS_Q;
}

queue_data_types queue_get_type(queue_str * me){
  return me->type;
}

unsigned int queue_get_size(queue_str * me){
  return me->data_buffer_size;
}

  
queue_out_types queue_data_write(queue_str * me , void* data , unsigned int data_size){
  /** error check **/
  if(data_size < 1){return ERROR_Q;}
  if(data == NULL){return ERROR_Q;}
  if(me == NULL){return ERROR_Q;}
  
  unsigned int index_counter = 0;
  
  do{
    switch(me->type){ 
      case INT_Q:    { int* holdi = (int*)data; me->data_buffer[ me->write_ptr++ ].data_i = (int)holdi[index_counter];                                             break;}
      case SHORT_Q:  { short* holds = (short*)data; me->data_buffer[ me->write_ptr++ ].data_s = (short)holds[index_counter];                                       break;}
      case CHAR_Q:   { char* holdc = (char*)data; me->data_buffer[ me->write_ptr++ ].data_c = (char)holdc[index_counter];                                          break;}
      case DOUBLE_Q: { double* holdd = (double*)data; me->data_buffer[ me->write_ptr++ ].data_d = (double)holdd[index_counter];                                    break;}
      case UINT_Q:   { unsigned int* holdui = (unsigned int*)data; me->data_buffer[ me->write_ptr++ ].data_ui = (unsigned int)holdui[index_counter];               break;}
      case USHORT_Q: { unsigned short* holdus = (unsigned short*)data; me->data_buffer[ me->write_ptr++ ].data_us = (unsigned short)holdus[index_counter];         break;}
      case UCHAR_Q:  { unsigned char* holduc = (unsigned char*)data; me->data_buffer[ me->write_ptr++ ].data_uc = (unsigned char)holduc[index_counter];            break;}
    }
  
    check_write_ptr(me);
    
    index_counter++;
    
  }while( index_counter < data_size);
  
  return SUCCESS_Q;
}


queue_out_types queue_data_read(queue_str * me , void* out_buffer, unsigned int out_buffer_size){
  /** error check **/
  if(out_buffer_size < 1){return ERROR_Q;}
  if(out_buffer == NULL){return ERROR_Q;}
  if(me == NULL){return ERROR_Q;}
  if(out_buffer_size > (me->data_buffer_size-1)){return ERROR_Q;}
  
  unsigned int index_counter = 0;
  
  do{  
      if(queue_is_empty(me) == FALSE_Q){
          switch(me->type){ 
            case INT_Q:    { int *out_ref_buffer = (int*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_i ;                           break;}
            case SHORT_Q:  { short *out_ref_buffer = (short*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_s ;                       break;}
            case CHAR_Q:   { char *out_ref_buffer = (char*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_c ;                         break;}
            case DOUBLE_Q: { double *out_ref_buffer = (double*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_d ;                     break;}
            case UINT_Q:   { unsigned int *out_ref_buffer = (unsigned int*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_ui ;        break;}
            case USHORT_Q: { unsigned short *out_ref_buffer = (unsigned short*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_us ;    break;}
            case UCHAR_Q:  { unsigned char *out_ref_buffer = (unsigned char*)out_buffer; *(out_ref_buffer + index_counter ) =  me->data_buffer[ me->read_ptr++ ].data_uc ;      break;}
          }
      }
      else{ break; }
      check_read_ptr(me);
      index_counter++;
  }while( index_counter < out_buffer_size);   
    
  return SUCCESS_Q;
}

