#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0;
#define ERROR_INPUT 1
#define ERROR_MEMORY 2
#define MAX_LEN 6

typedef struct node
{
    void *coeff;
    void *power;
    struct node *next;    
} node_t;

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