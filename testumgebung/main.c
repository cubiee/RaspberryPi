#include <stdio.h>
#include "DS18B20.h"

int main(void){ 
      
  DS18B20 sensor1 = NewSensor("28-0316451002ff");
  DS18B20 sensor2 = NewSensor("28-0316475929ff");
  DS18B20 sensor3 = NewSensor("28-041652badcff");

  int check1 = ReadTemp(&sensor1);
  int check2 = ReadTemp(&sensor2);
  int check3 = ReadTemp(&sensor3);

  if(check1)
  {
    printf("Sensor 1 Temperatur = %.3f\n", sensor1.temp);
  }
  else
  {
    PrintSensorError(&sensor1);
  }

  if(check2)
  {
    printf("Sensor 2 Temperatur = %.3f\n", sensor2.temp);
    fflush(stdout);
  }
  else
  {
    PrintSensorError(&sensor2);
  }

  if(check3)
  {
    printf("Sensor 3 Temperatur = %.3f\n", sensor3.temp);
    fflush(stdout);
  }
  else
  {
    PrintSensorError(&sensor3);
    fflush(stdout);
  }
  return 0;
}