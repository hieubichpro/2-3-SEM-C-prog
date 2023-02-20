#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ARGC 2
#define MAX_ARGC 3

#define OK 0
#define ERROR_ARGV 1
#define ERROR_FILE 2
#define ERROR_INPUT 3
#define INVALID_SIZE 4
#define ERROR_MEMORY 5
#define INVALID_INPUT 6

typedef struct 
{
    char *name;
    float macca;
    float volumn;
} object_t;

#endif 