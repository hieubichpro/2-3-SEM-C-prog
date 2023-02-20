#include "unit_tests.h"

#include <check.h>

int run_one_test(Suite* tname);

int main(void)
{
    int no_failed = 0;
    Suite *s1 = test_find_negative();
    Suite *s2 = test_key();
    Suite *s3 = test_comparator();
    Suite *s4 = test_swap();
    Suite *s5 = test_mysort();
    Suite *s6 = test_check_file_in();
    Suite *s7 = test_check_file_out();  
    no_failed += run_one_test(s1);
    no_failed += run_one_test(s2);
    no_failed += run_one_test(s3);
    no_failed += run_one_test(s4);
    no_failed += run_one_test(s5);
    no_failed += run_one_test(s6);
    no_failed += run_one_test(s7);
}

int run_one_test(Suite* tname)
{
    SRunner *runner = srunner_create(tname);
    srunner_run_all(runner, CK_VERBOSE);
    int fails = srunner_ntests_failed(runner);
    srunner_free(runner);
    return fails;
}