#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 27
#define M_V_STR_SIZE 30
#define ARR_SIZE 16

#define FNAME_SUB_STR_SIZE 100

#define MIN_ARGS 2
#define MAX_ARGS 3

#define OK 0
#define ERR_READ_FILE 1
#define ERR_ARR_SIZE 2
#define ERR_NUM_OF_ARGS 3
#define ERR_NAME_SIZE 4
#define ERR_M_V 5
#define ERR_CLOSE_FILE 6
#define ERR_EMPTY_FILE 7


typedef struct
{
    char name[NAME_SIZE];
    double m;
    double v;
} item;

typedef item arr_items[ARR_SIZE];
typedef char string[FNAME_SUB_STR_SIZE];

int analyze_args(int argc, char **argv, string fname, string substr);
int get_data(arr_items arr, int *arr_size, string fname);
void print_item(const arr_items arr, const int index);
void print_inform(const arr_items arr, const int size_arr, int argc, string substr);
void bubble_sort(arr_items arr, int arr_size);

#endif 

