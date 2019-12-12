#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cLogging.h"

int cLoggingFile0flag = 0;
int cLoggingFile1flag = 0;
int cLoggingFile2flag = 0;
int cLoggingFile3flag = 0;
int cLoggingFile4flag = 0;

char customLogMsg0[CUSTOM_LOG_LEN] = "CUSTOM0";
char customLogMsg1[CUSTOM_LOG_LEN] = "CUSTOM1";
char customLogMsg2[CUSTOM_LOG_LEN] = "CUSTOM2";
char customLogMsg3[CUSTOM_LOG_LEN] = "CUSTOM3";
char customLogMsg4[CUSTOM_LOG_LEN] = "CUSTOM4";
char customLogMsg5[CUSTOM_LOG_LEN] = "CUSTOM5";
char customLogMsg6[CUSTOM_LOG_LEN] = "CUSTOM6";
char customLogMsg7[CUSTOM_LOG_LEN] = "CUSTOM7";
char customLogMsg8[CUSTOM_LOG_LEN] = "CUSTOM8";
char customLogMsg9[CUSTOM_LOG_LEN] = "CUSTOM9";

FILE *cLoggingFile0 = NULL;
FILE *cLoggingFile1 = NULL;
FILE *cLoggingFile2 = NULL;
FILE *cLoggingFile3 = NULL;
FILE *cLoggingFile4 = NULL;

int cLoggingOpenLogfile(char *filename, int filenmbr, char *mode)
{
	int status = 1;
	switch (filenmbr)
	{
	case LOGFILE_0:
		if (cLoggingFile0flag == 0)
		{
			cLoggingFile0 = fopen(filename, mode);
			if (NULL == cLoggingFile0)
			{
				status = 0;
			}
			else
			{
				cLoggingFile0flag = 1;
			}
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_1:
		if (cLoggingFile1flag == 0)
		{
			cLoggingFile1 = fopen(filename, mode);
			if (NULL == cLoggingFile1)
			{
				status = 0;
			}
			else
			{
				cLoggingFile1flag = 1;
			}
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_2:
		if (cLoggingFile2flag == 0)
		{
			cLoggingFile2 = fopen(filename, mode);
			if (NULL == cLoggingFile2)
			{
				status = 0;
			}
			else
			{
				cLoggingFile2flag = 1;
			}
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_3:
		if (cLoggingFile3flag == 0)
		{
			cLoggingFile3 = fopen(filename, mode);
			if (NULL == cLoggingFile3)
			{
				status = 0;
			}
			else
			{
				cLoggingFile3flag = 1;
			}
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_4:
		if (cLoggingFile4flag == 0)
		{
			cLoggingFile4 = fopen(filename, mode);
			if (NULL == cLoggingFile4)
			{
				status = 0;
			}
			else
			{
				cLoggingFile4flag = 1;
			}
		}
		else
		{
			status = 0;
		}
		break;
	}
	return status;
}

int cLoggingCloseLogfile(int fileNmbr)
{
	int status = 1;
	switch (fileNmbr)
	{
	case LOGFILE_0:
		if (1 == cLoggingFile0flag){
			fclose(cLoggingFile0);
			cLoggingFile0flag = 0;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_1:
		if (1 == cLoggingFile1flag){
			fclose(cLoggingFile1);
			cLoggingFile1flag = 0;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_2:
		if (1 == cLoggingFile2flag){
			fclose(cLoggingFile2);
			cLoggingFile2flag = 0;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_3:
		if (1 == cLoggingFile3flag){
			fclose(cLoggingFile3);
			cLoggingFile3flag = 0;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_4:
		if (1 == cLoggingFile4flag){
			fclose(cLoggingFile4);
			cLoggingFile4flag = 0;
		}
		else
		{
			status = 0;
		}
		break;
	}
	return status;
}

void cLoggingReset(void)
{
	strncpy(customLogMsg0, "CUSTOM0", CUSTOM_LOG_LEN);
	strncpy(customLogMsg1, "CUSTOM1", CUSTOM_LOG_LEN);
	strncpy(customLogMsg2, "CUSTOM2", CUSTOM_LOG_LEN);
	strncpy(customLogMsg3, "CUSTOM3", CUSTOM_LOG_LEN);
	strncpy(customLogMsg4, "CUSTOM4", CUSTOM_LOG_LEN);
	strncpy(customLogMsg5, "CUSTOM5", CUSTOM_LOG_LEN);
	strncpy(customLogMsg6, "CUSTOM6", CUSTOM_LOG_LEN);
	strncpy(customLogMsg7, "CUSTOM7", CUSTOM_LOG_LEN);
	strncpy(customLogMsg8, "CUSTOM8", CUSTOM_LOG_LEN);
	strncpy(customLogMsg9, "CUSTOM9", CUSTOM_LOG_LEN);

	if (1 == cLoggingFile0flag)
	{
		fclose(cLoggingFile0);
		cLoggingFile0flag = 0;
	}
	if (1 == cLoggingFile1flag)
	{
		fclose(cLoggingFile1);
		cLoggingFile1flag = 0;
	}
	if (1 == cLoggingFile2flag)
	{
		fclose(cLoggingFile2);
		cLoggingFile2flag = 0;
	}
	if (1 == cLoggingFile3flag)
	{
		fclose(cLoggingFile3);
		cLoggingFile3flag = 0;
	}
	if (1 == cLoggingFile4flag)
	{
		fclose(cLoggingFile4);
		cLoggingFile4flag = 0;
	}
}

int cLoggingLog(int filenmbr, int Mode, char *message)
{
	int status = 1;
	FILE *file = NULL;
	switch (filenmbr)
	{
	case LOGFILE_0:
		if (1 == cLoggingFile0flag)
		{
			file = cLoggingFile0;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_1:
		if (1 == cLoggingFile1flag)
		{
			file = cLoggingFile1;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_2:
		if (1 == cLoggingFile2flag)
		{
			file = cLoggingFile2;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_3:
		if (1 == cLoggingFile3flag)
		{
			file = cLoggingFile3;
		}
		else
		{
			status = 0;
		}
		break;
	case LOGFILE_4:
		if (1 == cLoggingFile4flag)
		{
			file = cLoggingFile4;
		}
		else
		{
			status = 0;
		}
		break;
	default:
		printf("FEHLER!\n");
		return 0;
	}
	if ((NULL == file) || (status == 0))
	{
		return 0;
	}
	else
	{
		time_t t;
		time(&t);

		struct tm *currentTime;
		currentTime = localtime(&t);
		char timestamp[30];

		strftime(timestamp, 30, FORMAT_STRING_TIME, currentTime);

		switch (Mode)
		{
		case CRITICAL_LOG:
			fprintf(file, FORMAT_STRING_LOGFILE, CRITICAL_MSG, timestamp, message);
			break;
		case ERROR_LOG:
			fprintf(file, FORMAT_STRING_LOGFILE, ERROR_MSG, timestamp, message);
			break;
		case WARNING_LOG:
			fprintf(file, FORMAT_STRING_LOGFILE, WARNING_MSG, timestamp, message);
			break;
		case INFO_LOG:
			fprintf(file, FORMAT_STRING_LOGFILE, INFO_MSG, timestamp, message);
			break;
		case DEBUG_LOG:
			fprintf(file, FORMAT_STRING_LOGFILE, DEBUG_MSG, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_0:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg0, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_1:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg1, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_2:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg2, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_3:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg3, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_4:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg4, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_5:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg5, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_6:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg6, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_7:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg7, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_8:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg8, timestamp, message);
			break;
		case CUSTOM_LOG_MSG_9:
			fprintf(file, FORMAT_STRING_LOGFILE, customLogMsg9, timestamp, message);
			break;
		}
		return 1;
	}
}

void cLoggingSetCustomLogMsg(int CustomMsgNmbr, char *message)
{
	switch (CustomMsgNmbr)
	{
	case CUSTOM_LOG_MSG_0:
		memset(customLogMsg0, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg0, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_1:
		memset(customLogMsg1, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg1, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_2:
		memset(customLogMsg2, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg2, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_3:
		memset(customLogMsg3, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg3, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_4:
		memset(customLogMsg4, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg4, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_5:
		memset(customLogMsg5, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg5, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_6:
		memset(customLogMsg6, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg6, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_7:
		memset(customLogMsg7, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg7, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_8:
		memset(customLogMsg8, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg8, message, CUSTOM_LOG_LEN - 1);
		break;
	case CUSTOM_LOG_MSG_9:
		memset(customLogMsg9, '\0', CUSTOM_LOG_LEN * sizeof(char));
		strncat(customLogMsg9, message, CUSTOM_LOG_LEN - 1);
		break;
	default:
		printf("FEHLER!\n");
	}
}
