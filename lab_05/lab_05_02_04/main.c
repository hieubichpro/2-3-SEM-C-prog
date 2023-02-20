#include "my_funcs.h"

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    double ave;
    if (argc != 2 || f == NULL)
    {
        printf("Input Error");
        fclose(f);
        return EXIT_FAILURE;
    }
    int rc = process(f, &ave);
    if (rc != OK)
        return EXIT_FAILURE;
    printf("ave = %lf\n", ave);
    fclose(f);
    return EXIT_SUCCESS;
}