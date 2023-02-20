#include "../inc/memory.h"

node_t *new_node(const void *data)
{
    node_t *new = malloc(sizeof(node_t));
    if (new)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

void free_node(node_t *node)
{
    if (node)
    {
        free(node);
        node = NULL;
    }
}

void free_list(list_t *src)
{
    iter_t j = begin(NULL);
    for (iter_t i = begin(src); check(&i); i = j)
    {
        node_t *i_node = get_node(&i);
        node_t *j_node = get_node(&j);
        j_node = i_node->next;
        free_node(i_node);
    }
}