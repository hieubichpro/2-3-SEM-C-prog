#include <stdio.h>

#define NMAX 10
#define NMIN 1

#define OK 0
#define ELEMENT_ERROR -2
#define LOGIC_ERROR -1
#define INPUT_OK 1

int get_arr(int arr[NMAX][NMAX], int *row, int *col)
{
    int rc;
    rc = scanf("%d", row);
    if (rc != 1 || *row > NMAX || *row < NMIN)
        return LOGIC_ERROR;
    rc = scanf("%d", col);
    if (rc != 1 || *col > NMAX || *col < NMIN)
        return LOGIC_ERROR;
    int s;
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *col; j++)
        {
            if (scanf("%d", &s) == 1)
                arr[i][j] = s; 
            else
                return ELEMENT_ERROR; 
        } 
    return OK; 
}

int sum_ele(int a[NMAX][NMAX], int j, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += a[j][i];
    return sum;
}

void sort(int a[NMAX][NMAX], int n, int m)
{
    int jmin, buf;
    for (int i = 0; i < n; i++)
    {
        jmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sum_ele(a, j, m) < sum_ele(a, jmin, m))
                jmin = j;
        }
        for (int j = 0; j < m; j++)
        {
            buf = a[jmin][j];
            for (int k = jmin; k > i; k--)
                a[k][j] = a[k - 1][j];
            a[i][j] = buf;
        }
    }
}

void write_matrix(int a[NMAX][NMAX], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int arr[NMAX][NMAX];
    int row, col;
    int err = get_arr(arr, &row, &col);
    if (err == OK)
    {
        sort(arr, row, col);
        write_matrix(arr, row, col);
        return OK;
    }
    if (err == LOGIC_ERROR)
    {
        fprintf(stderr, "Logic Error");
        return LOGIC_ERROR;
    }
    fprintf(stderr, "Input Error");
    return ELEMENT_ERROR;
}
