#include "../inc/sort.h"

int comparator(const void *p, const void *q)
{
    const int *n1 = p;
    const int *n2 = q;
    return *n1 - *n2;
}

void swap(void *a, void *b, size_t size)
{
    char temp;
    for (char *c1 = a, *c2 = b; (size_t) (c1 - (char*) a) < size; c1++, c2++)
    {
        temp = *c1;
        *c1 = *c2;
        *c2 = temp;
    }
}

void mysort(void *base, size_t num, size_t size, int (*comparator)(const void*, const void*))
{
    for (char *pi = (char*) base; (size_t) (pi - (char*) base) < num * size; pi += size)
        for (char *pj = (char*) base; (size_t) (pj - (char*) base) < (size_t) ((num - 1) * size - (pi - (char*) base)); pj += size)
        {
            if (comparator(pj, pj + size) > 0)
                swap(pj, pj + size, size);
        }
}