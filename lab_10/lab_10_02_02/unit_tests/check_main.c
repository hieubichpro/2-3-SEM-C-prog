#include "check.h"
#include "check_polynome.h"

int main(void)
{
    Suite *suite_test = suite_create("test");

    suite_test = get_suite(suite_test);

    SRunner *runner_test = srunner_create(suite_test);

    srunner_run_all(runner_test, CK_VERBOSE);

    int errors = srunner_ntests_failed(runner_test);

    srunner_free(runner_test);

    return errors;
}
