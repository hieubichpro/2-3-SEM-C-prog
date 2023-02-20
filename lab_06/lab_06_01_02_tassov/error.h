#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>

#define FILE_NAME_SIZE 100
#define STRING_MAX 25
#define ARRAY_MAX 15
#define SUB_STRING_SIZE 100

#define LOWER_LIMIT_ARGC 2
#define UPPER_LIMIT_ARGC 3

#define END_FILE -1

#define OK 0
#define ARGS_ERROR 1
#define ERR_SIZE_SUBSTR 9
#define ERR_OPEN_FILE 2
#define ERR_READ_FILE 3
#define ERR_DATA 4
#define ERR_WEIGHT 5
#define ERR_VOLUME 6
#define ARRAY_SIZE_ERROR 7

void message_error(int rc);

#endif