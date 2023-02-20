#include "../inc/list.h"

iter_t begin(list_t *src)
{
    iter_t it;
    it.node = (src && !is_empty(l)) ? src->head : NULL;
    return it;
}

int check(iter_t *it)
{
    return it->node ? 1 : 0;
}

int check_finish(node_t *node)
{
    return (*(int*)(node->power) == 0) ? 1 : 0;
}

int check_next(iter_t *it)
{
    return it->node->next ? 1 : 0;
}

void next_next(iter_t *it)
{
    it->node = it->node->next->next;
}

void next(iter_t *it)
{
    it->node = it->node->next;
}

void list_to_null(list_t *src)
{
    src->head = NULL;
    src->tail = NULL;
}

iter_t next_iter(iter_t *i)
{
    iter_t i_next = begin(NULL);
    i_next.node = i->node->next;
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

node_t *get_node(iter_t *it)
{
    if (!it || !it->node)
        return NULL;
    return it->node;
}

void push_back(list_t *src, node_t *elem)
{
    if (!src || !elem)
        return;

    node_t *head = get_head(src);
    node_t *tail = get_tail(src);

    if (is_empty(src))
    {
        head = elem;
        tail = elem;
    }
    else
    {
        tail->next = elem;
        tail = elem;
    }
    src->head = head;
    src->tail = tail;
}

