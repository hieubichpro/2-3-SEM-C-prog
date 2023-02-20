#include "file_work.h"
#include "item.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3) 
    {
        message_error(ARGS_ERROR);
        return ARGS_ERROR;
    }

    item items_array[ARRAY_MAX];
    int items_len;

    int rc = open_file_and_read_items(items_array, &items_len, argv[1], ARRAY_MAX);
    
    if (rc != OK)
    {
        message_error(rc);
        return rc;
    }

    if (argc == 2)
        sort_and_print_data(items_array, items_len);
    else if (!strcmp(argv[2], "ALL"))
        print_data(items_array, items_len);
    else
        print_data_by_filter(items_array, items_len, argv[2]);
    
    return rc;
}
