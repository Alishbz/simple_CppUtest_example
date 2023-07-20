/****************************************************************************************
* ALI SAHBAZ
*
* 
* LED Driver and Simple Queue Test with cppUtest TDD 
*
* Date          : 20.07.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com */
#include "CppUTest/CommandLineTestRunner.h"
 
int main()
{
 // const char * av_override[] = { "exe", "-v" }; //turn on verbose mode
const char * av_override[] = { "exe", "-v" };
  //return CommandLineTestRunner::RunAllTests(ac, av);
  return CommandLineTestRunner::RunAllTests(2, av_override);
  //return 0;
}
