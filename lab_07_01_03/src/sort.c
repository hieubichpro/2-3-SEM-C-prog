#include "../inc/functions.h"
#include "../inc/sort.h"

void swap(void *a, void *b, int size)
{
    for (char *p = a, *q = b; p < (char*)a + size; p++, q++)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
}

int mycmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void mysort(void *base, size_t len, size_t size, int (*cmp)(const void*, const void*))
{
    if (len <= 0 || base == NULL || cmp == NULL)
        return;

    char *pi, *pj;
    
    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = 0; j < len - i - 1; j++)
        {
            pi = (char*)base + j * size;
            pj = (char*)base + (j + 1) * size;
            if (mycmp(pi, pj) > 0)
                swap(pi, pj, size);
        }
    }
}
