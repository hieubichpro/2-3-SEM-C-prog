#include "../inc/helper.h"

int is_empty(list_t *src)
{
    return src->head ? 0 : 1;
}

void list_to_null(list_t *src)
{
    src->head = NULL;
    src->tail = NULL;
}

iter_t begin(list_t *src)
{
    iter_t it;
    it.node = (src && !is_empty(src)) ? src->head : NULL;
    return it;
}

int check(iter_t *it)
{
    return it->node ? 1 : 0;
}

void next(iter_t *it)
{
    it->node = it->node->next;
}

void *get_data(iter_t *it)
{
    if (!it || !it->node)
        return NULL;
    return it->node->data;
    
}

node_t *get_node(iter_t *it)
{
    if (!it || !it->node)
        return NULL;
    return it->node;
}

node_t *get_head(list_t *src)
{
    if (!src || !src->head)
        return NULL;
    return src->head;
}

node_t *get_tail(list_t *src)
{
    if (!src || !src->tail)
        return NULL;
    return src->tail;
}

iter_t next_iter(iter_t *it)
{
    iter_t tmp = begin(NULL);
    if (it->node->next)
        tmp.node = it->node->next;
    return tmp;
}