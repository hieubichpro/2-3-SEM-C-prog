#include "../inc/memory.h"

node_t *new_node(const void *coeff, const void *power)
{
    node_t *new = malloc(sizeof(node_t));
    if (node)
    {
        new->coeff = coeff;
        new->power = power;
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
        j = next_iter(&i);
        free_node(get_node(&i));
    }
    list_to_null(src);
}