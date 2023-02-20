#include "../inc/main.h"
#include "../inc/inout.h"
#include "../inc/sort.h"

int main(int argc, char **argv)
{
    if (argc != MIN_ARGC && argc != MAX_ARGC)
        return ERROR_ARGV;

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return ERROR_FILE;

    int obj_len = 0;
    object_t *obj_arr;

    if (read_object_len(&obj_len, f) != OK)
        return INVALID_INPUT;
    if (!obj_len)
        return INVALID_INPUT;

    obj_arr = (object_t*)malloc(obj_len * sizeof(object_t));
    if (!obj_arr)
        return ERROR_MEMORY;

    int rc = read_object(obj_arr, obj_len, f);

    fclose(f);

    if (rc)
        return rc;

    if (argc == MIN_ARGC)
        my_insert_sort(obj_arr, obj_len);
        
    print_object(obj_arr, obj_len, argc, argv);
    delete(obj_arr, obj_len);

    return OK;
}