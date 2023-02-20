#include "check_polynome.h"
#include "../inc/polynome.h"
#include "../inc/inout.h"

void fill_polynome(list_t *polynome)
{
    polynome->power = 4;
    factor_t *node;

    for (int i = 0; i < polynome->power; i++)
    {
        node = new_factor(polynome->power - i);
        push_end(polynome, node);
    }
}

void fill_derivative(list_t *polynome)
{
    polynome->power = 3;
    factor_t *node;

    node = new_factor(12);
    push_end(polynome, node);

    node = new_factor(6);
    push_end(polynome, node);

    node = new_factor(2);
    push_end(polynome, node);
}

void fill_add_polynome(list_t *polynome)
{
    polynome->power = 4;
    factor_t *node;

    for (int i = 0; i < polynome->power; i++)
    {
        node = new_factor((polynome->power - i) * 2);
        push_end(polynome, node);
    }
}

int compare_polynomes(factor_t *first, factor_t *second)
{
    for ( ; first; first = first->next)
    {
        if (first->value != second->value)
            return 1;
        second = second->next;
    }
    return 0;
}

START_TEST(test_get_value)
{
    list_t polynome;
    list_to_null(&polynome);
    fill_polynome(&polynome);

    int data = 7, true_result = 1534;
    int result = calc_value(polynome.head, data);

    delete(polynome.head);

    ck_assert_int_eq(true_result, result);
}
END_TEST

START_TEST(test_differentiate)
{
    list_t polynome;
    list_to_null(&polynome);
    fill_polynome(&polynome);

    list_t result;
    list_to_null(&result);
    fill_derivative(&result);

    find_new_factor(polynome.head, polynome.power);
    pop_end(&polynome);
    int rc = compare_polynomes(polynome.head, result.head);

    delete(polynome.head);
    delete(result.head);

    ck_assert_int_eq(rc, 0);
}
END_TEST


START_TEST(test_add_polynomes)
{
    list_t first;
    list_to_null(&first);
    fill_polynome(&first);

    list_t second;
    list_to_null(&second);
    fill_polynome(&second);

    list_t result;
    list_to_null(&result);
    fill_add_polynome(&result);

    plus(first.head, second.head);
    int rc = compare_polynomes(first.head, result.head);

    delete(first.head);
    delete(second.head);
    delete(result.head);

    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite *get_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_get_value);
    tcase_add_test(tc_pos, test_differentiate);
    tcase_add_test(tc_pos, test_add_polynomes);
    suite_add_tcase(s, tc_pos);

    return s;
}