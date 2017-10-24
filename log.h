/*
* log.h
*
*  Created on: 2017年10月19日
*      Author: asia
*/

#ifndef TINY_LOG
#define TINY_LOG

#include<stdio.h>
#include<time.h>

/* log color
BLACK        30
RED          31
GREEN        32
YELLOW       33
BLUE         34
MAGENTA      35
CYAN         36
WHITE        37
*/

/* if define this ,then log will be turned on .
if not,the log code will not be compiled to the program. */
#define LOG_ON

/* if you define this,terminal print different level log in different color */
#define COLOR_ON

/* log level for printing */
#define LOG_LEVEL INFO

#define USE_SYSLOG

#ifdef LOG_ON

/*log level*/
#define ERR  0
#define WARN 1
#define INFO 2

//char levelStr[10][10] = {
//	"ERR ",
//	"WARN",
//	"INFO"
//};


#define GET_LOCAL_TIME\
	struct tm ptm = {0};\
	char date[20] = {0};\
	time_t Now =time(NULL);\
	localtime_r(&Now, &ptm);\
	strftime(date,20,"%x %X",&ptm);


#define SYSLOG_LOG_INFO(format, ...)\
	do{\
        syslog(LOG_INFO,"[ %s %s: %d]%s:  "format"\n",\
               __FUNCTION__, __FILE__, __LINE__, "INFO", ##__VA_ARGS__);\
    }while(0)


#define SYSLOG_LOG_WARN(format, ...)\
	do{\
        syslog(LOG_WARNING,"[ %s %s: %d]%s:  "format"\n",\
                __FUNCTION__, __FILE__, __LINE__, "WARN", ##__VA_ARGS__);\
    }while(0)


#define SYSLOG_LOG_ERR(format, ...)\
	do{\
        syslog(LOG_ERR,"[ %s %s: %d]%s:  "format"\n",\
			 __FUNCTION__, __FILE__, __LINE__, "ERR", ##__VA_ARGS__);\
    }while(0)



#define COLOR_LOG_INFO(format, ...) \
	do{\
		GET_LOCAL_TIME\
		printf("[%s %s %s: %d]\033[1;32m%s\033[0m:  "format"\n",\
		date, __FUNCTION__, __FILE__, __LINE__, "INFO", ##__VA_ARGS__);\
	}while(0)

#define NORM_LOG_INFO(format, ...)\
	do{\
		GET_LOCAL_TIME\
        printf("[%s %s %s: %d]%s:  "format"\n",\
                date, __FUNCTION__, __FILE__, __LINE__, "INFO", ##__VA_ARGS__);\
    }while(0)



#define COLOR_LOG_WARN(format, ...) \
	do{\
		GET_LOCAL_TIME\
		printf("[%s %s %s: %d]\033[1;33m%s\033[0m:  "format"\n",\
				date, __FUNCTION__, __FILE__, __LINE__, "WARN", ##__VA_ARGS__);\
	}while(0)

#define NORM_LOG_WARN(format, ...)\
	do{\
		GET_LOCAL_TIME\
        printf("[%s %s %s: %d]%s:  "format"\n",\
                date, __FUNCTION__, __FILE__, __LINE__, "WARN", ##__VA_ARGS__);\
    }while(0)



#define COLOR_LOG_ERR(format, ...) \
	do{\
		GET_LOCAL_TIME\
		printf("[%s %s %s: %d]\033[1;31m%s\033[0m:  "format"\n",\
				date, __FUNCTION__, __FILE__, __LINE__, "ERR", ##__VA_ARGS__);\
	}while(0)

#define NORM_LOG_ERR(format, ...)\
	do{\
		GET_LOCAL_TIME\
        printf("[%s %s %s: %d]%s:  "format"\n",\
				date, __FUNCTION__, __FILE__, __LINE__, "ERR", ##__VA_ARGS__);\
    }while(0)


#ifdef USE_SYSLOG
#include <syslog.h>
#if (LOG_LEVEL == INFO)
#define PRINT_LOG_ERR(format, ...)   SYSLOG_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  SYSLOG_LOG_WARN(format,  ##__VA_ARGS__)
#define PRINT_LOG_INFO(format, ...)  SYSLOG_LOG_INFO(format,  ##__VA_ARGS__)
#elif (LOG_LEVEL == WARN )
#define PRINT_LOG_ERR(format, ...)   SYSLOG_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  SYSLOG_LOG_WARN(format,  ##__VA_ARGS__)
#define PRINT_LOG_INFO(format, ...)  do{}while(0)
#elif (LOG_LEVEL == ERR )
#define PRINT_LOG_ERR(format, ...)   SYSLOG_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  do{}while(0)
#define PRINT_LOG_INFO(format, ...)  do{}while(0)
#endif
#else
#if (LOG_LEVEL == INFO) 	
#ifdef COLOR_ON
#define PRINT_LOG_ERR(format, ...)   COLOR_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  COLOR_LOG_WARN(format,  ##__VA_ARGS__)
#define PRINT_LOG_INFO(format, ...)  COLOR_LOG_INFO(format,  ##__VA_ARGS__)
#else
#define PRINT_LOG_ERR(format, ...)   NORM_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  NORM_LOG_WARN(format,  ##__VA_ARGS__)
#define PRINT_LOG_INFO(format, ...)  NORM_LOG_INFO(format,  ##__VA_ARGS__)
#endif
#elif (LOG_LEVEL == WARN )
#ifdef COLOR_ON
#define PRINT_LOG_ERR(format, ...)   COLOR_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  COLOR_LOG_WARN(format,  ##__VA_ARGS__)
#define PRINT_LOG_INFO(format, ...)  do{}while(0)
#else
#define PRINT_LOG_ERR(format, ...)   NORM_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  NORM_LOG_WARN(format,  ##__VA_ARGS__)
#define PRINT_LOG_INFO(format, ...)  do{}while(0)
#endif
#elif (LOG_LEVEL == ERR )
#ifdef COLOR_ON
#define PRINT_LOG_ERR(format, ...)   COLOR_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  do{}while(0)
#define PRINT_LOG_INFO(format, ...)  do{}while(0)
#else
#define PRINT_LOG_ERR(format, ...)   NORM_LOG_ERR(format,  ##__VA_ARGS__)
#define PRINT_LOG_WARN(format, ...)  do{}while(0)
#define PRINT_LOG_INFO(format, ...)  do{}while(0)
#endif
#endif
#endif
#else /* Don't compile log to the program*/
#define PRINT_LOG_ERR(format, ...)  do{}while(0)
#define PRINT_LOG_WARN(format, ...) do{}while(0)
#define PRINT_LOG_INFO(format, ...) do{}while(0)

#endif /* log ON OFF switch */ 


void conectRsyslog(void);

void DisconectRsyslog(void);

#endif /* MYWORK_MYLOG_LOG_H_ */
