#ifndef _SORT_H_
#define _SORT_H_

#include "struct.h"
#include "functions.h"
#include "memory.h"
#include "helper.h"

void sorted_insert(list_t *src, node_t *node, comparator cmp);

void sort(list_t *src, list_t *dst, comparator cmp);

void del_element(list_t *src, node_t *elem, comparator cmp);

void remove_duplicate(list_t *src, comparator cmp);

#endif