#include "../inc/func_matrix.h"

int search_row(matrix a)
{
    int i_min = 0, j_min = 0;

    for (int j = 0; j < a.c; j++)
        for (int i = 0; i < a.r; i++)
            if (a.matrix[i][j] <= a.matrix[i_min][j_min])
            {
                i_min = i;
                j_min = j;
            }

    return i_min;
}

void free_row(matrix *a, int numb_row)
{
    free(a->matrix[numb_row]);

    for (int i = numb_row; i < a->r - 1; i++)
        a->matrix[i] = a->matrix[i + 1];
}

void del_rows(matrix *a)
{
    int numb_row;

    while (a->r > a->c)
    {
        numb_row = search_row(*a);
        free_row(a, numb_row);
        (a->r)--;
    }
}

int search_col(matrix a)
{
    int i_min = 0, j_min = 0;

    for (int j = 0; j < a.c; j++)
        for (int i = 0; i < a.r; i++)
            if (a.matrix[i][j] <= a.matrix[i_min][j_min])
            {
                i_min = i;
                j_min = j;
            }

    return j_min;
}

void free_col(matrix *a, int numb_column)
{
    for (int i = 0; i < a->r; i++)
        for (int j = numb_column; j < a->c - 1; j++)
            a->matrix[i][j] = a->matrix[i][j + 1];
}

void del_cols(matrix *a)
{
    int numb_column;
    while (a->c > a->r)
    {
        numb_column = search_col(*a);
        free_col(a, numb_column);
        (a->c)--;
    }
}

void reduce_matrix(matrix *a)
{
    if (a->r > a->c)
        del_rows(a);
    else if (a->r < a->c)
        del_cols(a);
}

int arithmetic_mean(matrix *a, int j)
{
    int sum = 0;
    for (int i = 0; i < a->r - 1; i++)
        sum += a->matrix[i][j];
    int arith_mean = sum / (double)(a->r - 1);
    return arith_mean;
}

int add_row(matrix *a)
{
    int **p = realloc(a->matrix, ++a->r * sizeof(int*));

    if (!p)
    {
        free_mem(a->matrix, --a->r);
        return ERR_MEMORY; 
    }

    a->matrix = p;
    a->matrix[a->r - 1] = malloc(a->c * sizeof(int));
    if (!(a->matrix[a->r - 1]))
    {
        free_mem(a->matrix, a->r);
        return ERR_MEMORY; 
    }
    for (int j = 0; j < a->c; j++)
        a->matrix[a->r - 1][j] = arithmetic_mean(a, j);
    return OK;
}

int max(int *a, int *b)
{
    return *a > *b ? *a : *b;
}

int add_column(matrix *a)
{
    int *p;

    for (int i = 0; i < a->r; i++)
    {
        p = realloc(a->matrix[i], ++a->c * sizeof(int));
        if (!p)
        {
            free_mem(a->matrix, a->r);
            return ERR_MEMORY; 
        }
        a->matrix[i] = p;
    }

    for (int i = 0; i < a->r; i++)
    {
        int max_elem = a->matrix[i][0];

        for (int j = 1; j < a->c - 1; j++)
            max_elem = max(&max_elem, &a->matrix[i][j]);

        a->matrix[i][a->c - 1] = max_elem;
    }
    return OK;
}

int change_matrix(matrix *a, int new_size)
{
    int rc;
    while (a->r < new_size) 
    {
        rc = add_row(a);
        if (rc)
            return rc;
    }
    while (a->r < new_size) 
    {
        rc = add_column(a);
        if (rc)
            return rc;
    }
    return OK;
}

int fill_in_to_become_squre(matrix *a, matrix *b)
{
    int r;

    if (a->r < b->r)
    {
        r = change_matrix(a, b->r);

        if (r)
        {
            free_mem(b->matrix, b->r);
            return r;
        }
    }
    else if (a->r > b->r)
    {
        r = change_matrix(b, a->r);

        if (r)
        {
            free_mem(a->matrix, a->r);
            return r;
        }
    }
    return OK;
}

void copy_matrix(int **src, int **dst, 
int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dst[i][j] = src[i][j];
}

int find_element(matrix *a, matrix *b, int i, int j)
{
    int elem = 0;

    for (int k = 0; k < a->c; k++)
        elem += a->matrix[i][k] * b->matrix[k][j];

    return elem;
}

void matrix_multiplication(matrix *res, matrix *a, matrix *b)
{
    for (int i = 0; i < res->r; i++)
        for (int j = 0; j < res->c; j++)
            res->matrix[i][j] = find_element(a, b, i, j);
}

int identity_matrix(matrix *a, int size)
{   
    a->r = size;
    a->c = size;
    a->matrix = allocate_matrix(a->r, a->c);
    if (!a->matrix)
        return ERR_MEMORY;
    for (int i = 0; i < a->r; i++)
        for (int j = 0; j < a->c; j++)
            a->matrix[i][j] = (i == j ? 1 : 0);
    return OK;
}

int matrix_exp(matrix *a, int power_mat)
{
    matrix res;

    int r = identity_matrix(&res, a->r);
    if (r)
        return r;

    matrix interm_res;

    r = identity_matrix(&interm_res, a->r);
    if (r)
    {
        free_mem(res.matrix, res.r);
        return r;
    }

    for (int i = 0; i < power_mat; i++)
    {
        matrix_multiplication(&res, &interm_res, a);
        copy_matrix(res.matrix, interm_res.matrix, res.r, res.c);
    }

    copy_matrix(res.matrix, a->matrix, res.r, res.c);
    free_mem(res.matrix, res.r);
    free_mem(interm_res.matrix, interm_res.r);

    return OK;
}

int matrix_exponentiation(matrix *a, matrix *b)
{
    int power_a, power_b;
    int r = input_power(&power_a, &power_b);

    if (r)
    {
        free_mem(a->matrix, a->r);
        free_mem(b->matrix, b->r);
        return r;
    }

    r = matrix_exp(a, power_a);
    if (r)
    {
        free_mem(a->matrix, a->r);
        free_mem(b->matrix, b->r);
        return r;
    }
    
    r = matrix_exp(b, power_b);
    if (r)
    {
        free_mem(a->matrix, a->r);
        free_mem(b->matrix, b->r);
        return r;
    }
    return OK;
}

int get_result(matrix *res, matrix *a, matrix *b)
{
    res->r = a->r;
    res->c = b->c;
    res->matrix = allocate_matrix(res->r, res->c);

    if (!res->matrix)
        return ERR_MEMORY;

    matrix_multiplication(res, a, b);

    return OK;
}
