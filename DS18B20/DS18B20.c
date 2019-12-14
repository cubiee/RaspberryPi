#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bool.h"
#include "DS18B20.h"

char w1_path[PATH_LENGTH] = "/sys/bus/w1/devices/w1_bus_master1/";
char w1_slaves[SLAVE_LENGTH] = "w1_master_slaves";
char device[DEVICE_LENGTH] = "28-0316451002ff";
char zusatz[ADD_LENGTH] = "/w1_slave";

DS18B20 NewSensor(void)
{
  /*
  Funktion:
    DS18B20 NewSensor(void);
  Beschreibung:
    Konstruktor funktion für DS18B20 structs
  Aufruf:
    s = NewSensor();
  Rückgabewert(s):
    DS18B20 struct mit defaultwerten
  */

  DS18B20 s;

  //strings in struct mit '\0' initialisieren
  memset(s.deviceID, '\0', DEVICE_LENGTH);
  memset(s.directory, '\0', PATH_LENGTH);
  memset(s.devicepath, '\0', MAX_DEVICE_PATH_SIZE);
  memset(s.checkpath, '\0', MAX_CHECK_PATH_SIZE);
  
  //Standard deviceID -> struct
  strcpy(s.deviceID, device);

  //Standard directory -> struct
  strcpy(s.directory, w1_path);

  //Checkpath generieren -> struct
  strcpy(s.checkpath, w1_path);
  strcat(s.checkpath, w1_slaves);
  
  //Devicepath generieren -> struct
  strcpy(s.devicepath, w1_path);
  strcat(s.devicepath, device);
  strcat(s.devicepath, zusatz);
  
  //temp auf 0 setzen
  s.temp = 0;

  //mode auf normal setzen
  s.mode = NORMALMODE;

  //error auf NO_ERROR setzen
  s.errornumber = SENSOR_NO_ERROR;
  return s;
}

int CheckSensor(DS18B20 *s)
{
  /*
  Funktion:
    int CheckSensor(DS18B20 *s);
  Beschreibung:
    Funktion zum überprüfen ob sensor verfügbar und lesbar ist
  Aufruf:
    check = CheckSensor(s);
  Übergabewert(s):
    DS18B20 s, muss mit defaultwerten initialisiert sein oder mit eigenen werten gefüllt sein
  Rückgabewert(check):
    TRUE falls sensor vorhanden und lesbar ist
    FALSE falls sensor nicht vorhanden oder nicht lesbar ist
  */

  //checkfile öffnen, falls nicht möglich ausgabe und return false
  FILE *checkfile = fopen(s->checkpath,"r");
  if((NULL == checkfile)){
    if(s->mode)
    {
      printf("Unable to open checkpath at: %s\n", s->checkpath);
    }
    s->errornumber = SENSOR_CHECKPATH_FAIL;
    return FALSE;
  }
  else
  {
    //Buffer und foundswitch initialisieren
    char buffer[BUFFERSIZE];
    memset(buffer, '\0', BUFFERSIZE);
    BOOL found = FALSE;

    //so lange datei einlesen bis ende erreicht ist
    while(NULL != fgets(buffer, 2*DEVICE_LENGTH, checkfile))
    {
      //falls device gefunden found switch auf true
      if(NULL != strstr(buffer,s->deviceID))
      {
        found = TRUE;
      }
    }

    //falls device nicht gefunden wurde ausgabe und return false
    if(ISFALSE(found))
    {
      if(s->mode)
      {
        printf("Device %s not found\n", s->deviceID);
      }
      fclose(checkfile);
      s->errornumber = SENSOR_NO_DEVICE;
      return FALSE;
    }
    else
    {
      //sensor gefunden
      if(s->mode)
      {
        printf("Device %s found\n", s->deviceID);
      }
      fclose(checkfile);
      FILE *devicefile = fopen(s->devicepath,"r");
      if(NULL == devicefile)
      {
        //sensor konnte nicht geöffnet werden
        if(s->mode)
        {
          printf("Unable to open devicepath at: %s\n", s->devicepath);
        }
        s->errornumber = SENSOR_DEVICEPATH_FAIL;
        return FALSE;
      }
      else
      {
        //sensor ready
        if(s->mode)
        {
          printf("Device %s ready\n", s->deviceID);
        }
        fclose(devicefile);
        return TRUE;
      }
    }
  }
}

int ReadTemp(DS18B20 *s)
{
  /*
  Funktion:
    int ReadTemp(DS18B20 *s);
  Beschreibung:
    Funktion zum einlesen der temperatur wird danach im struct abgespeichert
  Aufruf:
    check = ReadTemp(s);
  Übergabewert(s):
    DS18B20 s, muss mit defaultwerten initialisiert sein oder mit eigenen werten gefüllt sein
  Rückgabewert(check):
    TRUE falls temperatur lesbar
    FALSE falls temperatur nicht lesbar
  */

  //sensor überprüfen
  if(FALSE == CheckSensor(s))
  {
    //Sensor check fehlgeschlagen
    if(s->mode)
    {
      printf("Sensor check fehlgeschlagen\n");
    }
    return FALSE;
  }
  else
  {
    //Sensor file öffnen
    FILE *device = fopen(s->devicepath, "r");
    if(NULL == device)
    {
      //fehler beim öffnen des sensor files
      if(s->mode)
      {
        printf("Fehler beim öffnen des sensor files\n");
      }
      return FALSE;
    }
    else
    {
      //Buffer initialisieren und datei auslesen
      char buffer[BUFFERSIZE];
      char *temp;
      memset(buffer, '\0', BUFFERSIZE);
      fgets(buffer,BUFFERSIZE,device);
      memset(buffer, '\0', BUFFERSIZE);
      fgets(buffer,BUFFERSIZE,device);
      //suchen nach t=123456
      temp = strchr(buffer,'t');
      if(NULL == temp)
      {
        if(s->mode)
        {
          printf("Fehler beim auslesen der temperatur\n");
        }
        return FALSE;
      }
      else
      {
        sscanf(temp,"t=%s",temp);
        s->temp = atof(temp)/1000;
        fclose(device);
        return TRUE;
      }
    }
  }
}

void BusRead(void)
{
  /*
  Funktion:
    void BusRead(void);
  Beschreibung:
    Funktion überprüft den one wire bus des raspberry pi aus und gibt alle angeschlossenen devices aus
  Aufruf:
    BusRead();
  */
  //buffer initialisieren
  char buffer[BUFFERSIZE];
  memset(buffer, '\0', BUFFERSIZE);
  //checkfile öffnen
  FILE *checkfile = fopen("/sys/bus/w1/devices/w1_bus_master1/w1_master_slaves","r");
  if((NULL == checkfile)){
    printf("Unable to open checkpath at: %s\n", "/sys/bus/w1/devices/w1_bus_master1/w1_master_slaves");
  }
  else
  {
    //solange devices ausgeben bis dateiende erreicht ist
    while(NULL != fgets(buffer, 2*DEVICE_LENGTH, checkfile))
    {
      printf(buffer);
    }
  }
  return;
}

void PrintSensorError(DS18B20 *s)
{
  int Error = s->errornumber;
  switch (Error)
  {
  case SENSOR_NO_ERROR:
    printf("Kein Error gefunden\n");
    break;
  
  case SENSOR_CHECKPATH_FAIL:
    printf("Checkpath konnte nicht geoeffnet werden\n");
    break;

  case SENSOR_NO_DEVICE:
    printf("Sensor konnte nicht gefunden werden\n");
    break;

  case SENSOR_DEVICEPATH_FAIL:
    printf("Devicepath konnte nicht geoeffnet werden\n");
    break;

  default:
    printf("WUBWUB\n");
    break;
  }
}