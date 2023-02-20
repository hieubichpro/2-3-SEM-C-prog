#ifndef _HELPER_H_
#define _HELPER_H_

#include "struct.h"
#include "memory.h"
#include "sort.h"
#include "functions.h"

int is_empty(list_t *src);

void list_to_null(list_t *src);

iter_t begin(list_t *src);

int check(iter_t *it);

void next(iter_t *it);

void *get_data(iter_t *it);

node_t *get_node(iter_t *it);

node_t *get_head(list_t *src);

node_t *get_tail(list_t *src);

iter_t next_iter(iter_t *it);

#endif