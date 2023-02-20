#include "check_pop.h"

START_TEST(pop_front_one_node)
{
    node_t *head = NULL;
    int arr[3] = {1, 2, 3};
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = (void *)(arr + 0);
    tmp->next = NULL;
    head = tmp;
    int *data = (int *)pop_front(&head);
    int rc = (*data != 1);
    ck_assert_int_eq(rc, 0);
    delete(head);
}
END_TEST

START_TEST(pop_front_three_node)
{
    node_t *head = NULL;
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        node_t *tmp = malloc(sizeof(node_t));
        tmp->data = (void *)(arr + i);
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
            continue;
        }
        node_t *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = tmp;
    }
    int *data = (int *)pop_front(&head);
    int rc = (*data != 1);
    ck_assert_int_eq(rc, 0);
    delete(head);
}
END_TEST

START_TEST(pop_back_one_node)
{
    node_t *head = NULL;
    int arr[3] = {1, 2, 3};
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = (void *)(arr + 0);
    tmp->next = NULL;
    head = tmp;
    int *data = (int *)pop_back(&head);
    int rc = (*data != 1);
    ck_assert_int_eq(rc, 0);
    delete(head);
}
END_TEST

START_TEST(pop_back_three_node)
{
    node_t *head = NULL;
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        node_t *tmp = malloc(sizeof(node_t));
        tmp->data = (void *)(arr + i);
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
            continue;
        }
        node_t *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = tmp;
    }
    int *data = (int *)pop_back(&head);
    int rc = (*data != 3);
    ck_assert_int_eq(rc, 0);
    delete(head);
}
END_TEST

Suite *pop_suite(Suite *s)
{
    TCase *tcase_pos = tcase_create("positives");
    tcase_add_test(tcase_pos, pop_front_one_node);
    tcase_add_test(tcase_pos, pop_front_three_node);
    tcase_add_test(tcase_pos, pop_back_one_node);
    tcase_add_test(tcase_pos, pop_back_three_node);

    suite_add_tcase(s, tcase_pos);

    return s;
}
