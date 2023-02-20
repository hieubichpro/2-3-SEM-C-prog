#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdio.h>

#define OK 0
#define ERR_INPUT -1
#define ERR_MEMORY -2

typedef struct matrix
{
    int **matrix;
    int r;
    int c;
} matrix;

void message_error(int rc);

#endif
