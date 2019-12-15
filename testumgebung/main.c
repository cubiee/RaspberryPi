#include <stdio.h>
#include "i2cLCD.h"

int main(void){
  I2CLCD d;
  printf("test");
  d = i2cLCDInit(27,4,16);
  return 0;
}