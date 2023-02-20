#ifndef _LIST_H_
#define _LIST_H_

#include "struct.h"
#include "functions.h"
#include "io.h"
#include "memory.h"
#include "polynome.h"

iter_t begin(list_t *src);

int check(iter_t *it);

int check_next(iter_t *it);

int check_finish(node_t *node);

void next(iter_t *it);

void next_next(iter_t *it);

void list_to_null(list_t *src);

iter_t next_iter(iter_t *i);

node_t *get_head(list_t *src);

node_t *get_tail(list_t *src);

node_t *get_node(iter_t *it);

void push_back(list_t *src, node_t *elem);

#endif