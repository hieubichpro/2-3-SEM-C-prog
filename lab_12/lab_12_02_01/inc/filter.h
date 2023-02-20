#ifndef __FILTER_H__
#define __FILTER_H__

#include "IO.h"
#include "sort.h"

int *find_negative(const int *pb_src, const int *pe_src);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
#endif