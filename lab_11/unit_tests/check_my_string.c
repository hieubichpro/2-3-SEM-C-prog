#include "../inc/my_snprintf.h"
#include <check.h>

//Test function my_snprintf
START_TEST(test_s)
{
    char src[100] = "anh yeu em";
    char dst[100];
    my_snprintf(dst, 100, "%s", src);
    ck_assert_str_eq(src, dst);
}
END_TEST

START_TEST(test_s_overflow)
{
    char src[100] = "anh yeu em";
    char dst[100];
    my_snprintf(dst, 4, "%s", src);
    ck_assert_str_eq(dst, "anh");
}
END_TEST

START_TEST(test_c_overflow)
{
    char c = 'c';
    char dst[100];
    snprintf(dst, 100, "%c", c);
    ck_assert_str_eq(dst, "c");
}
END_TEST

START_TEST(test_ld_pos)
{
    long int li = 100;
    char dst[100];
    my_snprintf(dst, 100, "%ld", li);
    ck_assert_str_eq(dst, "100");
}
END_TEST

START_TEST(test_ld_neg)
{
    long int li = 200;
    char dst[100];
    my_snprintf(dst, 100, "%ld", li);
    ck_assert_str_eq(dst, "200");
}
END_TEST

START_TEST(test_hx)
{
    int i = 100;
    char dst[100];
    my_snprintf(dst, 100, "%lx", i);
    ck_assert_str_eq(dst, "64");
}
END_TEST

START_TEST(test_s_hx_ld_c)
{
    int i = 100;
    long int lx = 100;
    char str[100] = "anh";
    long int li = -10;
    char dst[100];
    my_snprintf(dst, 100, "%s %lx", str, lx);
    char ccheck[100] = "anh 64";
    ck_assert_str_eq(dst, ccheck);
}
END_TEST

Suite* test_my_snprintf(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("SNPRINTF");

    tc_pos = tcase_create("Positives");
    tcase_add_test(tc_pos, test_hx);
    tcase_add_test(tc_pos, test_c_overflow);
    tcase_add_test(tc_pos, test_ld_neg);
    tcase_add_test(tc_pos, test_ld_pos);
    tcase_add_test(tc_pos, test_s_hx_ld_c);
    tcase_add_test(tc_pos, test_s);
    tcase_add_test(tc_pos, test_s_overflow);

    suite_add_tcase(s, tc_pos);

    return s;
}