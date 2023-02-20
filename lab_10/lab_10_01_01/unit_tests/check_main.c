#include <check.h>
#include "../inc/main.h"
#include "check_pop.h"
#include "check_reverse.h"
#include "check_sort.h"

int main(void)
{
    int failed = 0;
    
    Suite *s_pop = suite_create("pop_test");
    Suite *s_reverse = suite_create("reverse_test");
    Suite *s_sort = suite_create("sort_test");

    s_pop = pop_suite(s_pop);
    s_reverse = pop_suite(s_reverse);
    s_sort = pop_suite(s_sort);

    SRunner *runner_pop = srunner_create(s_pop);
    SRunner *runner_reverse = srunner_create(s_reverse);
    SRunner *runner_sort = srunner_create(s_sort);

    srunner_run_all(runner_pop, CK_VERBOSE);
    srunner_run_all(runner_reverse, CK_VERBOSE);
    srunner_run_all(runner_sort, CK_VERBOSE);

    failed += srunner_ntests_failed(runner_pop);
    failed += srunner_ntests_failed(runner_reverse);
    failed += srunner_ntests_failed(runner_sort);

    srunner_free(runner_pop);
    srunner_free(runner_reverse);
    srunner_free(runner_sort);

    return failed;
}