#ifndef _INOUT_H_
#define _INOUT_H_

#include "main.h"

int read_object_len(int *obj_len, FILE *file);
int read_name(char **name, FILE *file);
int read_object(object_t *obj_arr, int len, FILE *file);
void print_object(object_t *obj_arr, int len, int argc, char **argv);
void delete(object_t *obj_arr, int index);

#endif 