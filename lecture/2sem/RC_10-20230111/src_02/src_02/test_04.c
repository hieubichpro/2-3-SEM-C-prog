/*
Слайд 3
*/

#include <stdio.h>
#include <stdlib.h>

void print(const int *p, int n)
{
    printf("Array:");

    for (int i = 0; i < n; i++)
        printf(" %d", p[i]);

    printf("\n");
}

int compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;	// return *(int*)p - *(int*)q;
}

int main(void)
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    print(a, sizeof(a) / sizeof(a[0]));

    qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare_int);

    print(a, sizeof(a) / sizeof(a[0]));

    return 0;
}