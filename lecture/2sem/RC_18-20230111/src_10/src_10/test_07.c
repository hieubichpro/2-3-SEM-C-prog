// gcc ... -D TEST=5 -D TEST2="\"Hello\""

#include <stdio.h>

int main(void)
{
    printf("TEST %d\n", TEST);

    printf("TEST2 %s\n", TEST2);

    return 0;
}