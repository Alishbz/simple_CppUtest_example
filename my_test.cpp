
#include "CppUTest/TestHarness.h"
#include "stdio.h"
#include <string.h>
 


TEST_GROUP(FirstTestGroup)
{
  char output[100];
  const char * expected;
  
  // burasi her bir "TEST" blogunda tekrar init(setup) ve exit(teardown) oluyor
  void setup() {
     memset(output, 0xaa, sizeof output);
     expected = "";
     UT_PRINT("Beltchech Test Start \n");
  }
  void teardown() {
    UT_PRINT("Beltchech Test Finish \n");
  }
  
  void MY_CHECK_EQUAL(int x,int y)
  {
    if(x == 0xaa){UT_PRINT("way bee \n");}
     CHECK_EQUAL(x,y);
  }
 
  void expect(const char * s)
  {
    expected = s;
  }
  void given(int charsWritten)
  {
    LONGS_EQUAL(strlen(expected), charsWritten);
    STRCMP_EQUAL(expected, output);
    BYTES_EQUAL(0xaa, output[strlen(expected) + 1 ]);
  }
};

TEST(FirstTestGroup, FirstTest)
{
  FAIL("Fail me!");
}

TEST(FirstTestGroup, SecondTest)
{
  
  STRCMP_EQUAL("hello", "world");
}

TEST(FirstTestGroup, third_test)
{
  STRCMP_EQUAL("abo", "abo");
}

TEST(FirstTestGroup, forth_test)
{ 
  char output[5]; 
  memset(output, 0xaa, sizeof(output));
  CHECK_EQUAL(3, sprintf(output, "hey"));
  STRCMP_EQUAL("hey", output);
  CHECK_EQUAL(0xAA,output[4]);
}

TEST(FirstTestGroup, five_test)
{
  char output[20];
  memset(output, 0xaa, sizeof output); 
  CHECK_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
  STRCMP_EQUAL("Hello World\n", output);
  MY_CHECK_EQUAL(0xaa, output[13]);
}

TEST(FirstTestGroup, six_test)
{
  expect("Hello World\n");
  given(sprintf(output, "Hello %s\n", "World"));
}