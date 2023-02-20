#include "../inc/func_IO.h"
#include "../inc/error.h"

int input_size_matrix(int *row, int *col)
{
    int rc = scanf("%d", row);

    if (rc != 1 || *row <= 0)
        return ERR_INPUT;

    rc = scanf("%d", col); 

    if (rc != 1 || *col <= 0)
        return ERR_INPUT;

    return OK;
}

int input_matrix(matrix *a)
{
    a->matrix = allocate_matrix(a->r, a->c);

    if (!(a->matrix))
        return ERR_MEMORY;

    for (int i = 0; i < a->r; i++) 
    {
        for (int j = 0; j < a->c; j++) 
        {
            int rc = scanf("%d", (a->matrix)[i] + j);
            if (rc != 1)
            {
                free_mem(a->matrix, a->r);
                return ERR_INPUT;
            }
        }
    }
    return OK;
}

int read_matrices(matrix *a, matrix *b) 
{
    int rc = input_size_matrix(&(a->r), &(a->c));

    if (rc)
        return rc;

    rc = input_matrix(a);

    if (rc)
        return rc;

    rc = input_size_matrix(&(b->r), &(b->c));

    if (rc)
        return rc;

    rc = input_matrix(b);

    if (rc)
        return rc;

    return rc;  
}

void print_matrix(matrix *a)
{
    printf("\n");
    for (int i = 0; i < a->r; i++) 
    {
        for (int j = 0; j < a->c; j++) 
        {
            printf("%d ", (a->matrix)[i][j]);
        }
        printf("\n");
    }
}
int input_power(int *alpha, int *beta)
{
    int r;
    r = scanf("%d", alpha);
    if (r != 1)
        return ERR_INPUT; 
    if (*alpha < 0)
        return ERR_INPUT; 
    r = scanf("%d", beta); 
    if (r != 1)
        return ERR_INPUT; 
    if (*beta < 0)
        return ERR_INPUT;
    return OK;
}

void free_mem(int **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);

    free(data);
}

int **allocate_matrix(int r, int c)
{
    int **data = calloc(r, sizeof(int*));

    if (!data)
        return NULL;

    for (int i = 0; i < r; i++)
    {
        data[i] = malloc(c * sizeof(int));
        if (!data[i])
        {
            free_mem(data, r);
            return NULL;
        }
    }
    return data;
}
