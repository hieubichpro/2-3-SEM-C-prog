#include "check_cmp.h"

START_TEST(equal)
{
    object_t *obj;

    obj = (object_t *)malloc(2 * sizeof(object_t));

    obj->name = (char *)malloc(10 * sizeof(char));
    strcpy(obj->name, "milk");
    obj->macca = 10;
    obj->volumn = 10;

    (obj + 1)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 1)->name, "water");
    (obj + 1)->macca = 10;
    (obj + 1)->volumn = 10;

    float value = obj->macca / obj->volumn;
    int rc = cmp(value, obj + 1);
    ck_assert_int_eq(rc, 0);
    delete(obj, 2);
}
END_TEST

START_TEST(greater)
{
    object_t *obj;

    obj = (object_t *)malloc(2 * sizeof(object_t));

    obj->name = (char *)malloc(10 * sizeof(char));
    strcpy(obj->name, "milk");
    obj->macca = 10;
    obj->volumn = 1;

    (obj + 1)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 1)->name, "water");
    (obj + 1)->macca = 10;
    (obj + 1)->volumn = 10;

    float value = obj->macca / obj->volumn;
    int rc = cmp(value, obj + 1);
    ck_assert_int_eq(rc, 0);
    delete(obj, 2);
}
END_TEST

START_TEST(lower)
{
    object_t *obj;

    obj = (object_t *)malloc(2 * sizeof(object_t));

    obj->name = (char *)malloc(10 * sizeof(char));
    strcpy(obj->name, "milk");
    obj->macca = 10;
    obj->volumn = 10;

    (obj + 1)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 1)->name, "water");
    (obj + 1)->macca = 10;
    (obj + 1)->volumn = 1;

    float value = obj->macca / obj->volumn;
    int rc = cmp(value, obj + 1);
    ck_assert_int_eq(rc, 1);
    delete(obj, 2);
}
END_TEST

Suite *cmp_suite(Suite *s)
{
    TCase *tcase_pos;
    tcase_pos = tcase_create("positive");
    tcase_add_test(tcase_pos, equal);
    tcase_add_test(tcase_pos, greater);
    tcase_add_test(tcase_pos, lower);

    suite_add_tcase(s, tcase_pos);

    return s;
}