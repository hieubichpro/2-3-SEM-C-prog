#include "../inc/polynome.h"

int calc_value(list_t *src, const int value)
{
    int res = 0;

    for (iter_t i = begin(src); check(&i); next(&i))
    {
        node_t *curr = get_node(&i);
        res = res + *(int*)curr->coeff * pow(value, *(int*)curr->power);
    }

    return res;
}

void derivative(list_t *f)
{
    for (iter_t it = begin(f); check(&it); next(&it))
    {
        node_t *curr = get_node(&i);
        (*(int*)curr->coeff) *= (*(int*)curr->power);
        *(int*)curr->power -= 1;
    }
    pop_end(f);
}

void pop_end(list_t *f)
{
    iter_t j = begin(NULL);
    node_t *head = get_head(f), *tail = get_tail(f);

    for (iter_t i = begin(f); check(&i); next(&i))
    {
        node_t *i_node = get_node(&i);
        node_t *j_node = get_node(&j);
        if (i_node = tail)
        {
            if (j_node)
            {
                j_node->next = NULL;
                tail = j_node;
            }
            else
            {
                head = NULL;
                tail = NULL;
            }
            free_node(i_node);
        }
    }
    
}

void sum(iter_t *i, iter_t *j)
{
    for (; check(i) && check(j); next(i), next(j))
    {
        node_t *i_node = get_node(i);
        node_t *j_node = get_node(j);
        i_node->coeff += j_node->coeff;
    }
}

void shift_left(iter_t *it, int cnt)
{
    for (int i = 0; i < cnt; i++)
        next(it);
}

void plus(list_t *f1, list_t *f2)
{
    for (iter_t i = begin(f1); check(&i); next(&i))
    {
        int flag = 0;
        for (iter_t j = begin(f2); !flag && check(&j); next(&j))
        {
            if (get_power(&i) == get_power(&j))
            {
                *(int*)(i.node->coeff) += *(int*)(i.node->coeff);
                flag = 1;
            }
        }
    }
}

int degree(list_t *f)
{
    return *(int*)(f->head->power);
}

int get_power(iter_t *it)
{
    return *(int*)(it->node->power);
}

void print(iter_t *it)
{
    for (; check(it); next(it))
    {
        node_t *curr = get_node(it);
        printf("%d %d ", *(int*)(curr->coeff), *(int*)(curr->power));
    }
}

void devide_polynome(list_t *f, list_t *odd, list_t *even)
{
    for (iter_t i = begin(f); check(&i); next(&i))
    {
        if (get_power(&i) % 2 == 0)
        {
            push_back(even, get_node(&i));
        }
        else
        {
            push_back(odd, get_node(&i));
        }
    }
}