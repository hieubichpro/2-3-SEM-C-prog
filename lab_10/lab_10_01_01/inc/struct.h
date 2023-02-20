#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define OK         0
#define ERR_INPUT  1
#define ERR_MEMORY 2

typedef struct node node_t;

typedef int (*comparator)(const void *, const void *);

struct node
{
    void *data;
    node_t *next;
};

typedef struct
{
    node_t *head;
    node_t *tail;
} list_t;

typedef struct
{
    node_t *node;
} iter_t;

#endif
