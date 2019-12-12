# cLogging
Projekt zum schreiben von Logfiles wurde in zuge meiner Klausurvobereitung geschrieben und ist an das Logging Modul von Python angelegt jedoch ist ausser der Idee kaum noch eine Gemeinsamkeit zu finden. Es handelt sich nur um eine sehr einfache variante eines Loggers die nicht wirklich für viele zu gebrauchen sein wird, falls es jemand doch gebrauchen kann kann er es gerne nur für den privaten gebrauch verwenden.      
<br/>
## Öffnen eines Logfiles:  
```c
int cLoggingOpenLogfile(char *filename, int fileNmbr, char *mode);
```
### filenumber:  
- LOGFILE_0 - LOGFILE_4 : Logfile das geöffnet werden soll
### mode:  
- APPEND_MODE - Logfile wird im append mode geöffnet, Logs werden hinten angehängt.  
- OVERRIDE_MODE - Logfile wird im override mode geöffnet, Logfiles werden beim erstellen überschrieben.  
### Rückgabewert:  
- 0 falls Fehler auftritt.  
- 1 bei Erfolg.  
- Falls Logfile schon geöffnet wird 0 zurückgegeben.  
  
## Schliessen eines Logfiles:  
```c
int cLoggingCloseLogfile(int fileNmbr);
```
### fileNmbr:  
- LOGFILE_0 - LOGFILE_4 : Logfile das geschlossen werden soll 
## Log schreiben:  
```c
int cLoggingLog(int filenmbr, int Mode, char *message);
```
### filenmbr:  
- LOGFILE_0 - LOGFILE_4 : Logfile das beschrieben werden soll  
### Mode:  
- CRITICAL_MSG : CRITICAL als bezeichner  
- ERROR_MSG : ERROR als bezeichner  
- WARNING_MSG : WARNING als bezeichner  
- INFO_MSG : INFO als bezeichner  
- DEBUG_MSG : DEBUG als bezeichner 
- CUSTOM_LOG_MSG_0 - CUSTOM_LOG_MSG_9 : Custom bezeichner  
## Custom message erstellen: 
```c
void cLoggingSetCustomLogMsg(int CustomMsgNmbr, char *message);
```
### CustomMsgNmbr:  
- CUSTOM_LOG_MSG_0 - CUSTOM_LOG_MSG_9 : Speicherort des Custom Bezeichners  
## Modul Zurücksetzten:  
```c
void cLoggingReset(void);
```
- setzt das komplette Modul zurück  
- geöffnete Logfiles werden geschlossen  
- Custom Messages weden zurückgesetzt  
