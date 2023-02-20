#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ARG_ERR -1
#define READ_FILE_ERR -2
#define EMPTY_FILE -3
#define ALLOCATION_ERR -4
#define POINTER_ERR -5
#define FILTER_ERR -6
#define OPEN_FILE_ERR -7
#define ARR_ERR -8

typedef struct
{
    int *beg;
    int *end;
} arr;


void arr_to_null(arr *a);
int **get_pb(arr *a);
int **get_pe(arr *a);
size_t get_len(arr *a);
void free_arr(arr *a);

int check_open_file(FILE **f, const char *fname, const char *mode);
int count_num_of_elems(int *cnt, FILE *f);
int create_dynamic_array(int **ptr, const int n);
int get_numbers(arr *a, const char *fname);
void fill_array(arr *a, FILE *f);
int get_data(arr *a, FILE *f);
void write_numbers(arr *a, const char *fname);

void message_error(const int rc);

#endif