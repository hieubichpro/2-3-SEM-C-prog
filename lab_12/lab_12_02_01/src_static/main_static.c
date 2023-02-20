#include "../inc/process_sta.h"

int main(int argc, char **argv)
{
    int rc;
    if (argc == 3 || (argc == 4 && !strcmp(argv[3], "f")))
    {
        int *pb_src;
        int *pe_src;
        rc = process_read_numbers_from_file(&pb_src, &pe_src, *(argv + 1));
        if (rc == OK)
        {
            if (argc == 3)
            { 
                sort_and_write_without_filter(*(argv + 2), pb_src, pe_src);
            }
            else 
            {
                rc = sort_and_write_with_filter(*(argv + 2), pb_src, pe_src);
            }
            memory_deallocate(&pb_src);
        }
    }
    else 
        rc = INVALID_INPUT;
    show_error(rc);
    return rc;
}