#include <stdio.h>
#include "DS18B20.h"

int main(void){ 
  DS18B20 sensor1 = NewSensor();
  DS18B20 sensor2 = NewSensor();
  int check1 = ReadTemp(&sensor1);
  int check2 = ReadTemp(&sensor2);
  
  if(check1)
  {
    printf("Temperatur = %.3f\n", sensor1.temp);
  }
  else
  {
    PrintSensorError(&sensor1);
  }

  if(check2)
  {
    printf("Temperatur = %.3f\n", sensor2.temp);
  }
  else
  {
    PrintSensorError(&sensor2);
  }
  return 0;
}