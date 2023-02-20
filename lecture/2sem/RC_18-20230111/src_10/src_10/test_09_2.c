#include <stdio.h>

#define GLUE_HELPER(x, y) x##y
#define GLUE(x, y) GLUE_HELPER(x, y)

#define AVG(x) (((GLUE(max_, x)) - (GLUE(min_,x))) / (GLUE(x,_count)))

#define TIME time

int main(void)
{
    double max_v = 5, min_v = 0, v_count = 10;
    double max_time = 10, min_time = 5, time_count = 100;

    printf("avg(v) %f\n", AVG(v));

    printf("avg(TIME) %f\n", AVG(TIME));

    return 0;
}