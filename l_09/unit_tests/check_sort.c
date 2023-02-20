#include "check_sort.h"

START_TEST(no_sort)
{
    object_t *obj;

    obj = (object_t *)malloc(3 * sizeof(object_t));

    obj->name = (char *)malloc(10 * sizeof(char));
    strcpy(obj->name, "milk");
    obj->macca = 10;
    obj->volumn = 3;

    (obj + 1)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 1)->name, "water");
    (obj + 1)->macca = 10;
    (obj + 1)->volumn = 2;

    (obj + 2)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 2)->name, "lemonade");
    (obj + 2)->macca = 10;
    (obj + 2)->volumn = 1;

    my_insert_sort(obj, 3);
    int flag = 1;
    if (strcmp(obj->name, "milk") != 0 || obj->volumn != 3 || obj->macca != 10)
        flag = 0;
    if (strcmp((obj + 1)->name, "water") != 0 || (obj + 1)->volumn != 2 || (obj + 1)->macca != 10)
        flag = 0;
    if (strcmp((obj + 2)->name, "lemonade") != 0 || (obj + 2)->volumn != 1 || (obj + 2)->macca != 10)
        flag = 0;
    ck_assert_int_eq(flag, 1);
    delete(obj, 3);
}
END_TEST

START_TEST(sort_not_all)
{
    object_t *obj;

    obj = (object_t *)malloc(3 * sizeof(object_t));

    obj->name = (char *)malloc(10 * sizeof(char));
    strcpy(obj->name, "milk");
    obj->macca = 10;
    obj->volumn = 3;

    (obj + 1)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 1)->name, "lemonade");
    (obj + 1)->macca = 10;
    (obj + 1)->volumn = 1;

    (obj + 2)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 2)->name, "water");
    (obj + 2)->macca = 10;
    (obj + 2)->volumn = 2;

    my_insert_sort(obj, 3);
    int flag = 1;
    if (strcmp(obj->name, "milk") != 0 || obj->volumn != 3 || obj->macca != 10)
        flag = 0;
    if (strcmp((obj + 1)->name, "water") != 0 || (obj + 1)->volumn != 2 || (obj + 1)->macca != 10)
        flag = 0;
    if (strcmp((obj + 2)->name, "lemonade") != 0 || (obj + 2)->volumn != 1 || (obj + 2)->macca != 10)
        flag = 0;
    ck_assert_int_eq(flag, 1);
    delete(obj, 3);
}
END_TEST

START_TEST(sort_all)
{
    object_t *obj;

    obj = (object_t *)malloc(3 * sizeof(object_t));

    obj->name = (char *)malloc(10 * sizeof(char));
    strcpy(obj->name, "lemonade");
    obj->macca = 10;
    obj->volumn = 1;

    (obj + 1)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 1)->name, "milk");
    (obj + 1)->macca = 10;
    (obj + 1)->volumn = 3;

    (obj + 2)->name = (char *)malloc(10 * sizeof(char));
    strcpy((obj + 2)->name, "water");
    (obj + 2)->macca = 10;
    (obj + 2)->volumn = 2;

    my_insert_sort(obj, 3);
    int flag = 1;
    if (strcmp(obj->name, "milk") != 0 || obj->volumn != 3 || obj->macca != 10)
        flag = 0;
    if (strcmp((obj + 1)->name, "water") != 0 || (obj + 1)->volumn != 2 || (obj + 1)->macca != 10)
        flag = 0;
    if (strcmp((obj + 2)->name, "lemonade") != 0 || (obj + 2)->volumn != 1 || (obj + 2)->macca != 10)
        flag = 0;
    ck_assert_int_eq(flag, 1);
    delete(obj, 3);
}
END_TEST

Suite *sort_suite(Suite *s)
{
    TCase *tcase_pos;
    tcase_pos = tcase_create("positive");
    tcase_add_test(tcase_pos, no_sort);
    tcase_add_test(tcase_pos, sort_not_all);
    tcase_add_test(tcase_pos, sort_all);

    suite_add_tcase(s, tcase_pos);

    return s;
}