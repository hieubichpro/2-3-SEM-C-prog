#include "../inc/functions.h"

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

void push_front(list_t *src, node_t *elem)
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
        elem->next = head;
        head = elem;
    }
    src->head = head;
    src->tail = tail;
}

list_t find(list_t *src, const void *data, comparator cmp)
{
    list_t res;
    list_to_null(&res);

    for (iter_t it = begin(src); check(&it); next(&it))
    {
        void *curr_data = get_data(&it);
        node_t *curr_node = get_node(&it);
        if (cmp(data, curr_data) == 0)
        {
            push_back(&res, curr_node);
        }
    }

    return res;
}

void *pop_front(list_t *src)
{
    if (!src || is_empty(src))
        return NULL;

    node_t *old_head = get_head(src);
    void *data = old_head->data;
    src->head = old_head->next;
    free_node(old_head);
    return data;
}

int reverse(list_t *src)
{
    int rc = OK;

    if (!src || is_empty(src))
        rc = ERR_INPUT;
    else
    {
        list_t dst;
        list_to_null(&dst);
        for (iter_t it = begin(src); !rc && check(&it); next(&it))
        {
            void *data = pop_front(src);
            node_t *node = new_node(data);
            if (node)
            {
                push_front(&dst, node);
            }
            else
            {
                rc = ERR_MEMORY;
            }
        }
    }
    return rc;
}