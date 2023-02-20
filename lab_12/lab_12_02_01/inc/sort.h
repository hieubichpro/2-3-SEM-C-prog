#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q);
void swap(void *a, void *b, size_t size);
void mysort(void *base, size_t num, size_t size, int (*comparator)(const void*, const void*));

#endif