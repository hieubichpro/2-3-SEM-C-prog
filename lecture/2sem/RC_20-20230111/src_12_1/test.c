#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 2

void fill(int *a, int n, int m)
{
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            a[i * m + j] = p + 1;
        p *= 10;
    }
}

void print(int *a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i * m + j]);
        printf("\n");
    }
}

int main(void)
{
    int n = N, m = M;
    int *d = malloc(m * n * sizeof(int));
    // int s[N*M];
    fill(d, n, m);
    print(d, n, m);
    return 0;
}