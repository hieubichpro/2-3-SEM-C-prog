#include <stdio.h>

#define STR(x) #x

#define NAME Bob

int main(void)
{
    puts(STR(10)); // puts("10")

    puts(STR(NAME)); // puts("NAME")

    return 0;
}
