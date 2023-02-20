#include "my_funcs.h"

int main(void)
{
    FILE *f = stdin;
    int cnt_max;
    int stt = process(f, &cnt_max);
    if (stt == OK)
    {
        fprintf(stdout, "Length_max monotony sequence: %d\n", cnt_max);
        return EXIT_SUCCESS;
    }
    else
    {
        fprintf(stdout, "Input error");
        return EXIT_FAILURE;
    }
}