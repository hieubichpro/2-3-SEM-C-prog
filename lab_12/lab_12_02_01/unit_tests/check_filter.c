#include "../inc/filter.h"
#include <check.h>

//Test function find_negative
START_TEST(test_find_negative_in_pos_arr)
{
    int arr[3] = {1, 2, 3};
    int *pt_neg = find_negative(arr, arr + 3);
    ck_assert_ptr_eq(pt_neg, NULL);
}
END_TEST

START_TEST(test_find_negative_in_usual_arr)
{
    int arr[5] = {1, 2, 3, -1, 4};
    int *pt_neg = find_negative(arr, arr + 5);
    ck_assert_ptr_ne(pt_neg, NULL);
}
END_TEST

//Test function key
START_TEST(test_key_with_pointer_null)
{
    int rc = key(NULL, NULL, NULL, NULL);
    ck_assert_int_eq(rc, POINTER_ERROR);
}
END_TEST

START_TEST(test_key_with_bad_pointer)
{
    int *pb_src = calloc(3, sizeof(int));
    int *pe_src = pb_src + 3;
    int rc = key(pb_src, pe_src, NULL, NULL);
    free(pb_src);
    ck_assert_int_eq(rc, POINTER_ERROR);
}
END_TEST

START_TEST(test_key_empty_new_arr)
{
    int arr[3] = {-1, 2, 3};
    int *pb_dst;
    int *pe_dst;
    int rc = key(arr, arr + 2, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, DATA_ERROR);
}
END_TEST

START_TEST(test_key_usual_arr)
{
   int arr[3] = {1, 2, -33};
    int *pb_dst;
    int *pe_dst;
    int rc = key(arr, arr + 2, &pb_dst, &pe_dst);
    free(pb_dst); 
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_pos_arr)
{
   int arr[3] = {1, 2, 33};
    int *pb_dst;
    int *pe_dst;
    int rc = key(arr, arr + 2, &pb_dst, &pe_dst);
    free(pb_dst); 
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* test_find_negative(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("Find_negavitie");
    tc_neg = tcase_create("Negatives");
    tcase_add_test(tc_neg, test_find_negative_in_pos_arr);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("Positives");
    tcase_add_test(tc_pos, test_find_negative_in_usual_arr);
    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* test_key(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("Key");
    tc_neg = tcase_create("Negatives");
    tcase_add_test(tc_neg, test_key_with_pointer_null);
    tcase_add_test(tc_neg, test_key_with_bad_pointer);
    tcase_add_test(tc_neg, test_key_empty_new_arr);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("Positives");
    tcase_add_test(tc_pos, test_key_usual_arr);
    tcase_add_test(tc_pos, test_key_pos_arr);
    suite_add_tcase(s, tc_pos);

    return s;
}