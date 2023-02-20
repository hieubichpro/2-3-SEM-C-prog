#ifndef _FUNC_MATRIX_H_
#define _FUNC_MATRIX_H_

#include <math.h>

#include "error.h"
#include "func_IO.h"

void copy_matrix(int **src, int **dst, int r, int c);
int find_element(matrix *a, matrix *b, int i, int j);
void matrix_multiplication(matrix *res, matrix *a, matrix *b);
int identity_matrix(matrix *a, int size);
int matrix_exp(matrix *a, int power_mat);
int search_row(matrix a);
void free_row(matrix *a, int numb_row);
void del_rows(matrix *a);
int search_col(matrix a);
void free_col(matrix *a, int numb_column);
void del_cols(matrix *a);
int arithmetic_mean(matrix *a, int j);
int add_row(matrix *a);
int add_column(matrix *a);
int change_matrix(matrix *a, int new_size);
int max(int *a, int *b);

void reduce_matrix(matrix *a);
int fill_in_to_become_squre(matrix *a, matrix *b);
int matrix_exponentiation(matrix *a, matrix *b);
int get_result(matrix *res, matrix *a, matrix *b);

#endif
