/*
Header zum auslesen von ds18b20 temperatur sensoren
benötigt: DS18B20.h DS18B20.c bool.h
noch zu erledigen:
1. beim auslesen der temperaturwerde auf richtigkeit der werte prüfen
*/

#ifndef DS18B20_H
#define DS18B20_H

#define ERROR_NODIR 9999
#define ERROR_NODEV 9998

#define DEVICE_LENGTH 20
#define PATH_LENGTH 40
#define SLAVE_LENGTH 17
#define ADD_LENGTH 10
#define MAX_CHECK_PATH_SIZE (PATH_LENGTH + SLAVE_LENGTH)
#define MAX_DEVICE_PATH_SIZE (PATH_LENGTH + DEVICE_LENGTH + ADD_LENGTH)

#define BUFFERSIZE (10*DEVICE_LENGTH)

//Ausgabemodus
#define DEBUGMODE 1
#define NORMALMODE 0

//Errornummern
#define SENSOR_NO_ERROR 0
#define SENSOR_CHECKPATH_FAIL 1
#define SENSOR_NO_DEVICE 2
#define SENSOR_DEVICEPATH_FAIL 3

typedef struct sensor_s
{
  float temp;
  char deviceID[DEVICE_LENGTH];
  char directory[PATH_LENGTH];
  char devicepath[MAX_DEVICE_PATH_SIZE];
  char checkpath[MAX_CHECK_PATH_SIZE];
  int mode;
  int errornumber;
} SENSOR;

SENSOR NewSensor(void);

int CheckSensor(SENSOR *s);

int ReadTemp(SENSOR *s);

void BusRead(void);

void PrintSensorError(SENSOR *s);

#endif