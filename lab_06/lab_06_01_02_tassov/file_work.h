#ifndef __FILE_WORK_H__
#define __FILE_WORK_H__

#include "item.h"

int read_line(char *str, FILE *f);
int convert_str_to_double(char *str, double *num);
int read_each_item(item *a, FILE *f);
void strdel(char *str, char pattern);

int read_all_items(item *array, int *cnt, int size_arr_max, FILE *f);
int open_file_and_read_items(item *array, int *cnt, char *fname, int size_arr_max);

#endif