#ifndef _FUNC_IO_H_
#define _FUNC_IO_H_

#include <stdio.h>
#include <stdlib.h>

#include "error.h"

int input_size_matrix(int *row, int *col);
int input_power(int *alpha, int *beta);
int input_matrix(matrix *a);
int **allocate_matrix(int n, int m);
void free_mem(int **data, int n);

int read_matrices(matrix *a, matrix *b);
void print_matrix(matrix *a);

#endif
