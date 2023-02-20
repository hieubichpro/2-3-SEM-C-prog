#include "../inc/sort.h"
#include <check.h>

//Test function comparator
START_TEST(test_comparator_eq_value)
{
    int n1 = 10;
    int n2 = 10;
    int rc = comparator(&n1, &n2);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_comparator_lt_value)
{
    int n1 = 0, n2 = 1;

    int rc = comparator(&n1, &n2);
    
    ck_assert_int_lt(rc, 0);
}
END_TEST

START_TEST(test_comparator_gt_value)
{
    int n1 = 10, n2 = 1;

    int rc = comparator(&n1, &n2);
    
    ck_assert_int_gt(rc, 0);
}
END_TEST

//Test function swap
START_TEST(test_swap_diff_value)
{
    int a = 100;
    int b = 0;
    swap(&a, &b, sizeof(int));
    ck_assert_int_eq(a, 0);
    ck_assert_int_eq(b, 100);
}
END_TEST

//Test fucntion mysort
START_TEST(test_mysort_usual_arr)
{
    int arr[5] = {3, 2, 1, 4, 5};
    mysort(arr, 5, sizeof(int), comparator);
    for (int i = 0; i < 4; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END_TEST

START_TEST(test_my_sort_eq_els)
{
    int arr[5] = {1, 1, 1, 1, 1};
    mysort(arr, 5, sizeof(int), comparator);
    for (int i = 0; i < 4; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END_TEST

START_TEST(test_my_sort_gt_els)
{
    int arr[5] = {1, 2, 3, 4, 5};
    mysort(arr, 5, sizeof(int), comparator);
    for (int i = 0; i < 4; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END_TEST

START_TEST(test_my_sort_lt_els)
{
    int arr[5] = {5, 4, 3, 2, 1};
    mysort(arr, 5, sizeof(int), comparator);
    for (int i = 0; i < 4; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END_TEST

Suite* test_comparator(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Comparator");
    
    tc_pos = tcase_create("Positives");
    tcase_add_test(tc_pos, test_comparator_eq_value);
    tcase_add_test(tc_pos, test_comparator_gt_value);
    tcase_add_test(tc_pos, test_comparator_lt_value);
    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* test_swap(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Swap");
    tc_pos = tcase_create("Positives");
    tcase_add_test(tc_pos, test_swap_diff_value);
    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* test_mysort(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Mysort");
    
    tc_pos = tcase_create("Positives");
    tcase_add_test(tc_pos, test_my_sort_eq_els);
    tcase_add_test(tc_pos, test_my_sort_gt_els);
    tcase_add_test(tc_pos, test_my_sort_lt_els);
    tcase_add_test(tc_pos, test_mysort_usual_arr);
    suite_add_tcase(s, tc_pos);

    return s;
}