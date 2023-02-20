#ifndef __CHECK_IO_H__
#define __CHECK_IO_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "error.h"

int check_open_file(FILE **f, char *fname);
int analyze_args(int argc, char **argv, char *filename, char *sub_string);
int check_sub_string(char *sub_string);

#endif