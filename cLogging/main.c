#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cLogging.h"

#define PUMPE_LOGFILE	LOGFILE_0
#define SENSOR_LOGFILE	LOGFILE_1
#define FILTER_LOGFILE	LOGFILE_2

#define PUMPE			CUSTOM_LOG_MSG_7
#define SENSOR			CUSTOM_LOG_MSG_8
#define FILTER			CUSTOM_LOG_MSG_9



int main(int argc, char *argv[]){
	cLoggingOpenLogfile("pumpe.log", PUMPE_LOGFILE, APPEND_MODE);
	cLoggingOpenLogfile("sensor.log", SENSOR_LOGFILE, APPEND_MODE);
	cLoggingOpenLogfile("filter.log", FILTER_LOGFILE, APPEND_MODE);

	cLoggingSetCustomLogMsg(PUMPE, "PUMPE");
	cLoggingSetCustomLogMsg(SENSOR, "SENSOR");
	cLoggingSetCustomLogMsg(FILTER, "FILTER");

	cLoggingLog(PUMPE_LOGFILE, PUMPE, "Pumpenlogfile");
	cLoggingLog(SENSOR_LOGFILE, SENSOR, "Sensorlogfile");
	cLoggingLog(FILTER_LOGFILE, FILTER, "Filterlogfile");

	cLoggingReset();
	return 0;
}
