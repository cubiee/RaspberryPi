#ifndef CLOGGING_H
#define CLOGGING_H
#define MAX_NMBR_LOGFILES		5
#define LOGFILE_0				0
#define LOGFILE_1				1
#define LOGFILE_2				2
#define LOGFILE_3				3
#define LOGFILE_4				4

#define CRITICAL_LOG			50
#define ERROR_LOG				40
#define WARNING_LOG				30
#define INFO_LOG				20
#define DEBUG_LOG				10

#define CUSTOM_LOG_LEN			200
#define MAX_NMBR_CUSTM_MSG		10
#define CUSTOM_LOG_MSG_0		0
#define CUSTOM_LOG_MSG_1		1
#define CUSTOM_LOG_MSG_2		2
#define CUSTOM_LOG_MSG_3		3
#define CUSTOM_LOG_MSG_4		4
#define CUSTOM_LOG_MSG_5		5
#define CUSTOM_LOG_MSG_6		6
#define CUSTOM_LOG_MSG_7		7
#define CUSTOM_LOG_MSG_8		8
#define CUSTOM_LOG_MSG_9		9

#define APPEND_MODE				"a"
#define OVERRIDE_MODE			"w"

#define FORMAT_STRING_LOGFILE	"%s;%s;%s\n"
#define FORMAT_STRING_TIME		"%d.%m.%y;%H:%M:%S"

#define CRITICAL_MSG			"CRITICAL"
#define ERROR_MSG				"ERROR"
#define WARNING_MSG				"WARNING"
#define INFO_MSG				"INFO"
#define DEBUG_MSG				"DEBUG"


extern FILE *cLoggingFile0;
extern FILE *cLoggingFile1;
extern FILE *cLoggingFile2;
extern FILE *cLoggingFile3;
extern FILE *cLoggingFile4;

extern int cLoggingFile0flag;
extern int cLoggingFile1flag;
extern int cLoggingFile2flag;
extern int cLoggingFile3flag;
extern int cLoggingFile4flag;

extern char customLogMsg0[CUSTOM_LOG_LEN];
extern char customLogMsg1[CUSTOM_LOG_LEN];
extern char customLogMsg2[CUSTOM_LOG_LEN];
extern char customLogMsg3[CUSTOM_LOG_LEN];
extern char customLogMsg4[CUSTOM_LOG_LEN];
extern char customLogMsg5[CUSTOM_LOG_LEN];
extern char customLogMsg6[CUSTOM_LOG_LEN];
extern char customLogMsg7[CUSTOM_LOG_LEN];
extern char customLogMsg8[CUSTOM_LOG_LEN];
extern char customLogMsg9[CUSTOM_LOG_LEN];

int cLoggingOpenLogfile(char *filename, int fileNmbr, char *mode);

int cLoggingCloseLogfile(int fileNmbr);

void cLoggingReset(void);

int cLoggingLog(int logfile, int Mode, char*message);

void cLoggingSetCustomLogMsg(int CustomMsgNmbr, char *message);

#endif