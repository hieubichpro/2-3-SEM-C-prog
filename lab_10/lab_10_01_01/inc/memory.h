#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "struct.h"
#include "functions.h"
#include "sort.h"
#include "helper.h"

node_t *new_node(const void *data);

void free_node(node_t *node);

void free_list(list_t *src);

#endif