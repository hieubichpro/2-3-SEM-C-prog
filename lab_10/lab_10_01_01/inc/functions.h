#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "struct.h"
#include "memory.h"
#include "sort.h"
#include "helper.h"

void push_back(list_t *src, node_t *elem);

void push_front(list_t *src, node_t *elem);

list_t find(list_t *src, const void *data, comparator cmp);

void *pop_front(list_t *src);

int reverse(list_t *src);

#endif