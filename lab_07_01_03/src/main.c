#include "../inc/functions.h"
#include "../inc/filter.h"
#include "../inc/sort.h"

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4 || (argc == 4 && strcmp(argv[3], "f")))
    {
        message_error(ARG_ERR);
        return ARG_ERR;
    }

    arr src;
    arr_to_null(&src);

    int rc = get_numbers(&src, argv[1]);
    
    if (rc)
    {
        message_error(rc);
        return rc;
    }

    arr dst;
    arr_to_null(&dst);
    
    if (argc == 4)
    {
        rc = key(*get_pb(&src), *get_pe(&src), get_pb(&dst), get_pe(&dst));
        free_arr(&src);
    }
    else
        dst = src;

    if (rc == OK)
    {
        mysort(*get_pb(&dst), get_len(&dst), sizeof(int), mycmp);
        write_numbers(&dst, argv[2]);
    }
    
    free_arr(&dst);
    message_error(rc);

    return rc;
}