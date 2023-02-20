#ifndef _SORT_H_
#define _SORT_H_

void swap(void *elem1, void *elem2, int size);
int mycmp(const void *a, const void *b);
void mysort(void *base, size_t len, size_t size, int (*cmp)(const void*, const void*));

#endif // !_SORT_H_
