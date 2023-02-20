#ifndef _MEMOMY_H_
#define _MEMORY_H_

#include "struct.h"
#include "functions.h"
#include "io.h"
#include "list.h"
#include "polynome.h"

node_t *new_node(const void *coeff, const void *power);

void free_node(node_t *node);

void free_list(list_t *src);

#endif