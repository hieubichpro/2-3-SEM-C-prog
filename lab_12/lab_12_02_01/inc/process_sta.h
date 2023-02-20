#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "filter.h"

void sort_and_write_without_filter(char *fname, int *pb_src, int *pe_src);
int sort_and_write_with_filter(char *fname, int *pb_src, int *pe_src);

#endif