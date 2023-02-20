#include "../inc/sort.h"

void sorted_insert(list_t *src, node_t *node, comparator cmp)
{
    int inserted = 0;
    
    node_t *first = get_head(src);
    if (cmp(first->data, node->data) > 0)
    {
        push_front(src, node);
        inserted = 1;
    }

    iter_t j = begin(src);
    iter_t i = next_iter(&j);

    for (; !inserted && check(&i); next(&i))
    {
        void *curr_data = get_data(&i);
        if (cmp(curr_data, node->data) > 0)
        {
            node_t *i_node = get_node(&i);
            node_t *j_node = get_node(&j);
            j_node->next = node;
            node->next = i_node;
            inserted = 1;
        }
    }

    if (!inserted)
    {
        push_back(src, node);
    }
}

void sort(list_t *src, list_t *dst, comparator cmp)
{
    list_to_null(dst);
    
    for (iter_t it = begin(src); check(&it); next(&it))
    {
        node_t *curr_node = get_node(&it);
        sorted_insert(dst, curr_node, cmp);
    }
}

void del_element(list_t *src, node_t *elem, comparator cmp)
{
    if (!src)
        return;

    node_t *first = get_head(src);

    int deleted = 0;

    if (cmp(first->data, elem->data) == 0)
    {
        node_t *tmp = src->head;
        src->head = src->head->next;
        free_node(tmp);
        delete = 1;
    }

    iter_t prev = begin(src);
    iter_t curr = next_iter(prev);
    for (; !deleted && check(&curr); next(&curr))
    {
        node_t *curr_node = get_node(&curr);
        if (cmp(curr_node->data, elem->data) == 0)
        {
            prev.node = curr.node->next;
            free_node(curr.node);
        }
        prev = curr;
    }

    if (prev.node->next == NULL)
        src->tail = prev;
}

void remove_duplicate(list_t *src, comparator cmp)
{
    list_t storage;
    list_to_null(&storage)

    for (iter_t i = begin(src);  check(&i); next(&i))
    {
        int found = 0;
        for (iter_t j = next_iter(&i); !found && check(&j); next(&j))
        {
            void *data_i = get_data(&i);
            void *data_j = get_data(&j);
            if (cmp(data_i, data_j) == 0)
            {
                found = 1;
                storage.push_back(get_node(&i));
            }
        }
    }

    for (iter_t i = begin(storage); check(&i); next(&i))
    {
        del_element(src, get_node(&i), cmp);
    }
}