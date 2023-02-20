#include "../inc/main.h"
#include "check.h"
#include "check_cmp.h"
#include "check_sort.h"

int main(void)
{
    int rc = 0;

    Suite *s_cmp = suite_create("cmp_test");
    Suite *s_sort = suite_create("sort_test");

    s_cmp = cmp_suite(s_cmp);
    s_sort = sort_suite(s_sort);

    SRunner *runner_cmp = srunner_create(s_cmp);
    SRunner *runner_sort = srunner_create(s_sort);

    srunner_run_all(runner_cmp, CK_VERBOSE);
    srunner_run_all(runner_sort, CK_VERBOSE);

    rc += srunner_ntests_failed(runner_cmp);
    rc += srunner_ntests_failed(runner_sort);

    srunner_free(runner_cmp);
    srunner_free(runner_sort);

    return rc;
}