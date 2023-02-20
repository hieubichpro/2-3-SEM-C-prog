#include "unit_tests.h"
#include <check.h>

int run_one_test(Suite* tname);

int main(void)
{
    int no_failed = 0;
    Suite *s1 = test_my_snprintf();

    no_failed += run_one_test(s1);

    return no_failed;
}

int run_one_test(Suite* tname)
{
    SRunner *runner = srunner_create(tname);
    srunner_run_all(runner, CK_VERBOSE);
    int fails = srunner_ntests_failed(runner);
    srunner_free(runner);
    return fails;
}
