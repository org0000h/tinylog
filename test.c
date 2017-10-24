#include <stdio.h>
#include "log2.h"
void main(){
int a = 1;
int b = 2;
int c = 3;
int d = 4;
//openlog("tinyLog", LOG_PID, LOG_USER);
conectRsyslog();

PRINT_LOG_ERR(" log message a = %d",a);
PRINT_LOG_WARN(" log message b = %d",b);
PRINT_LOG_INFO(" log message c = %d",c);
//closelog();
 DisconectRsyslog();

}





 
