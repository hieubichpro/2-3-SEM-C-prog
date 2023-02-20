#include "./inc/my_snprintf.h"
#include <string.h>
#include <limits.h>

int main(void)
{
    int a = 12345;
    long int b = 321234;
    char str[100];
    int cnt = convert_long_number_to_string(str, b, 'd', 100);
    printf("%d %s\n", cnt, str);
    return 0;
}
