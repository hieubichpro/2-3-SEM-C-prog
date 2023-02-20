#ifndef _UNIT_TESTS_H_
#define _UNIT_TESTS_H_

#include <stdio.h>
#include <check.h>
#include <stdlib.h>

Suite* test_find_negative(void);
Suite* test_key(void);
Suite* test_comparator(void);
Suite* test_swap(void);
Suite* test_mysort(void);
Suite* test_check_file_in(void);
Suite* test_check_file_out(void);
#endif