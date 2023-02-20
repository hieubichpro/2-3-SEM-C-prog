#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "error.h"

typedef void (*fn_mysort) (void *, size_t , size_t , int (*comparator)(const void*, const void*));
typedef int (*fn_write) (char *, int *, int *);
typedef void (*fn_memory_deallocate) (int **);
typedef int (*fn_key) (const int *, const int *, int **, int **);
typedef int (*fn_memory_all) (int **, int );
typedef int* (*fn_find_neg) (const int *, const int *);
typedef int (*fn_read) (int **pb_src, int **pe_src, char *fname);
typedef int (*fn_cmp) (const void *, const void *);
typedef int (*fn_key) (const int *, const int *, int **, int **);
int sort_and_write_without_filter(char *fname, int *pb_src, int *pe_src, void *lib);
int sort_and_write_with_filter(char *fname, int *pb_src, int *pe_src, void *lib);

#endif