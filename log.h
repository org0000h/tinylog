/*
 * log.h
 *
 *  Created on: 2017年10月19日
 *      Author: asia
 */

#ifndef MYWORK_MYLOG_LOG_H_
#define MYWORK_MYLOG_LOG_H_

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
#define LOG_LEVEL INFO

#define ERR  0
#define WARN 1
#define INFO 2

char levelStr[10][10] = {
    "ERR ",
    "WARN",
    "INFO"
    };

#define LOG(level, format, ...) \
        do{\
            if(level <= LOG_LEVEL){\
            struct tm ptm = { 0 };\
            char date[20] = {0};\
            time_t Now =time(NULL);\
            localtime_r(&Now, &ptm);\
            strftime(date,20,"%x %X",&ptm);\
            switch(level){\
                    case ERR:\
                        fprintf(stdout,"[%s %s %s: %d]\033[1;31m%s\033[0m:  "format"\n",\
                             date, __FUNCTION__, __FILE__, __LINE__, levelStr[level], ##__VA_ARGS__);\
                    break;\
                    case WARN:\
                        fprintf(stdout,"[%s %s %s: %d]\033[1;33m%s\033[0m:  "format"\n",\
                        date, __FUNCTION__, __FILE__, __LINE__, levelStr[level], ##__VA_ARGS__);\
                    break;\
                    case INFO:\
                        fprintf(stdout,"[%s %s %s: %d]\033[1;32m%s\033[0m:  "format"\n",\
                        date, __FUNCTION__, __FILE__, __LINE__, levelStr[level], ##__VA_ARGS__);\
                    break;\
                }\
            }\
        }while(0)\

#endif /* MYWORK_MYLOG_LOG_H_ */
