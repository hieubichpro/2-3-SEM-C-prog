#include <stdio.h>

#define AVG(x) (((max_##x) - (min_##x)) / (x##_count))

#define TIME time

int main(void)
{
    double max_v = 5, min_v = 0, v_count = 10;
    double max_time = 10, min_time = 5, time_count = 100;

    printf("avg(v) %f\n", AVG(v));

    printf("avg(TIME) %f\n", AVG(TIME));

    return 0;
}