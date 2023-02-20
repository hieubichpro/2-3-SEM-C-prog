#include "../inc/IO.h"
#include <check.h>

//Test function check_file_in
START_TEST(test_check_file_in_file_not_exit)
{
    FILE *f;
    int rc = check_file_in(&f, "test");
    ck_assert_int_eq(rc, OPEN_FILE_ERROR);
}
END_TEST

Suite* test_check_file_in(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Check_file_in");
    
    tc_pos = tcase_create("Negative");
    tcase_add_test(tc_pos, test_check_file_in_file_not_exit);
    suite_add_tcase(s, tc_pos);

    return s;
}

//Test function check_file_out
START_TEST(test_check_file_out_file_not_exit)
{
    FILE *f;
    int rc = check_file_out(&f, "");
    ck_assert_int_eq(rc, OPEN_FILE_ERROR);
}
END_TEST

Suite* test_check_file_out(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("Check_file_out");
    
    tc_pos = tcase_create("Negative");
    tcase_add_test(tc_pos, test_check_file_out_file_not_exit);
    suite_add_tcase(s, tc_pos);

    return s;
}