#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define OK 0
#define END_FILE -1
#define OPEN_FILE_ERROR -2
#define READ_FILE_ERROR -7
#define WRITE_FILE_ERROR -8
#define DATA_ERROR -3
#define MEMORY_ERROR -4
#define INVALID_INPUT -5
#define POINTER_ERROR -6
#define NOT_FOUND -9
#define LOAD_ERROR -10

void show_error(int rc);
#endif