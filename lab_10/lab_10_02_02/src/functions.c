#include "../inc/functions.h"

int process()
{
    char action[MAX_LEN];
    scanf("%s", action);

    if (strlen(action) >= MAX_LEN)
        return ERROR_INPUT;

    if (strcmp(action, "val") == 0)
        return get_value();
    if (strcmp(action, "ddx") == 0)
        return get_derivative();
    if (strcmp(action, "sum") == 0)
        return get_sum();
    if (strcmp(action, "dvd") == 0)
        return divide_polynome();
    return ERROR_INPUT;
}

int get_value(void)
{
    list_t f;
    list_to_null(&f);
    int rc = input_polynome(&f);
    if (rc)
        return rc;
    int value;
    if (scanf("%d", &value) != 1)
    {
        free_list(&f);
        return ERROR_INPUT;
    }
    printf("%d\n", calc_value(&f, value));
    free_list(&f);
    return OK;
}

int get_derivative(void)
{
    list_t f;
    list_to_null(&f);
    int rc = input_polynome(&f);
    if (rc)
        return rc;
    derivative(&f);
    free_list(&f);
    return OK;
}

int get_sum(void)
{
    list_t f, g;
    list_to_null(&f);
    int rc = input_polynome(&f);
    if (rc)
        return rc;
    list_to_null(&g);
    rc = input_polynome(&g);
    if (rc)
    {
        free_list(f);
        return rc;
    }
    plus(&f, &g);
    if (degree(&f) > degree(&g))
        print_polynome(&f);
    else
        print_polynome(&g);
    free_list(&f);
    free_list(&g);
    return OK;
}

int divide(void)
{
    list_t f;
    list_to_null(&f);
    int rc = input_polynome(&f);
    if (rc)
        return rc;

    list_t even, odd;
    list_to_null(&even);
    list_to_null(&odd);

    devide_polynome(&f, &even, &odd);
    
    print_polynome(&even);
    printf("\n");
    print_polynome(&odd);
    printf("L\n");
    free_list(&f);
    free_list(&odd);
    free_list(&even);
    return OK;
}   