#include "../inc/my_snprintf.h"
#include <string.h>
#include <limits.h>

int main(void) // s d ld lx
{
    long int li1 = 123;
    long int li2 = -123;
    long int li = 7;
    int i1 = 12;
    int i2 = -12;
    char some_text[100] = "newyearinrussia";
    char str[100];
    int len = my_snprintf(str, 100, "%s %lx %lx %d %d", some_text, li1, li2, i1, i2);
    printf("%d %s\n", len, str);
    len = snprintf(str, 100, "%s %lx %lx %d %d", some_text, li1, li2, i1, i2);
    printf("%d %s\n", len, str);

    printf("%d\n", my_snprintf(NULL, 0,"why... %s %lx notme", some_text, li));    
    printf("%d\n", snprintf(NULL, 0,"why... %s %lx notme", some_text, li));

    return EXIT_SUCCESS;
}

// #include "../inc/my_snprintf.h"
// #include <string.h>
// #include <limits.h>

// int main(void)
// {
//     long int b = 123;
//     char str[100];
//     int cnt = convert_long_number_to_string(str, b, 'd', 100);
//     printf("%d %s\n", cnt, str);
//     return 0;
// }
