#include "../inc/io.h"

int input_elem(int *coeff, int *power)
{
    int rc = scanf(coeff, power);
    
    if (rc != 2)
        rc = ERR_INPUT;

    return rc;
}

int input_polynome(list_t *f)
{
    int rc = OK, finish = 0;
    int coeff, power;
    node_t *elem;
    for (; !rc && !finish;)
    {
        if (input_elem(&coeff, &power) != OK)
            rc = ERROR_INPUT;
        else if ((elem = new_node(&coeff, &power)) == NULL)
            rc = ERROR_MEMORY;
        else
        {
            push_back(f, elem);
            finish = check_finish(elem);
        }
    }
    if (rc)
        free_list(f);
    return rc;
}

void print_node(node_t *curr)
{
    printf("%d %d", *(int*)(curr->coeff), *(int*)(curr->power));
}

void print_polynome(list_t *f)
{
    for (iter_t i = begin(f); check(&i); next(&i))
    {
        node_t *curr = get_node(&i);
        print_node(curr);
    }

    printf("L\n");
}