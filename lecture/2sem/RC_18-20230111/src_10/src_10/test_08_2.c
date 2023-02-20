#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define NAME Bob

int main(void)
{
    puts(STR(10)); //puts("10");

    puts(STR(NAME)); // puts("")

    return 0;
}