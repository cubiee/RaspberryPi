#include <stdio.h>
#include "i2cLCD.h"

int main(void){ 
  I2CLCD display;
  display = i2cLCDInit(0x27,4,16);
  clear(&display);
  display_string(&display, "hallo", 1, 4);
  return 0;
}