#include "my_funcs.h"

int analyze_args(int argc, char **argv, string fname, string substr)
{
    if (argc < MIN_ARGS || argc > MAX_ARGS)
        return ERR_NUM_OF_ARGS;

    strcpy(fname, argv[1]);

    if (argc == 3)
        strcpy(substr, argv[2]);

    return OK;
}

int get_data(arr_items arr, int *arr_size, string fname)
{
    FILE *f = fopen(fname, "r");

    if (f == NULL)
        return ERR_READ_FILE;
        
    if (feof(f))
    {
        if (fclose(f) == EOF)
            return ERR_CLOSE_FILE;
        return ERR_CLOSE_FILE;
    }
    
    double m, v;

    for (int i = 0; !feof(f); i++, (*arr_size)++)
    {
        if (fgets(arr[i].name, NAME_SIZE, f) == NULL)
            return ERR_NAME_SIZE;

        if (strlen(arr[i].name) == NAME_SIZE - 1)
            return ERR_NAME_SIZE;

        m = fscanf(f, "%lf\n", &arr[i].m);
        v = fscanf(f, "%lf\n", &arr[i].v);

        if (!m || m == EOF)
            return ERR_READ_FILE;
        if (!v || v == EOF)
            return ERR_READ_FILE; 

        if (arr[i].m <= 0 || arr[i].v <= 0)
            return ERR_M_V;

        if (*arr_size == ARR_SIZE - 1)
            return ERR_ARR_SIZE;
    }

    if (fclose(f) == EOF)
        return ERR_CLOSE_FILE;

    return OK;
}

void print_item(const arr_items arr, const int index)
{
    printf("%s", arr[index].name);
    printf("%.6f\n", arr[index].m);
    printf("%.6f\n", arr[index].v);
}

void print_inform(const arr_items arr, const int size_arr, int argc, string substr)
{
    for (int i = 0; i < size_arr; i++)
    {
        if (argc == 2 || strcmp(substr, "ALL") == 0)
            print_item(arr, i);
        else
        {
            if (strncmp(substr, arr[i].name, strlen(substr)) == 0)
                print_item(arr, i);
        }
    }
}

void bubble_sort(arr_items arr, int arr_size)
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = 0; j < arr_size - 1 - i; j++)
        {
            if (arr[j].m / arr[j].v > arr[j + 1].m / arr[j + 1].v)
            {
                item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
