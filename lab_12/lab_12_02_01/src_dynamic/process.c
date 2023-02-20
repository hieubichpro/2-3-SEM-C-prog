#include "../inc/process.h"

int sort_and_write_without_filter(char *fname, int *pb_src, int *pe_src, void *lib)
{
    int rc = OK;
    fn_mysort mysort = dlsym(lib, "mysort");
    if (!mysort)
        rc = LOAD_ERROR;
    
    fn_cmp comparator = dlsym(lib, "comparator");
    if (!rc && !comparator)
        rc = LOAD_ERROR;

    fn_write process_write_numbers_to_file = dlsym(lib, "process_write_numbers_to_file");
    if (!rc && !process_write_numbers_to_file)
        rc = LOAD_ERROR;

    if (!rc)
    {
        mysort(pb_src, pe_src - pb_src, sizeof(int), comparator);
        process_write_numbers_to_file(fname, pb_src, pe_src);
    }
    return rc;
}

int sort_and_write_with_filter(char *fname, int *pb_src, int *pe_src, void *lib)
{
    int rc = OK;
    fn_mysort mysort = dlsym(lib, "mysort");
    if (!mysort)
        rc = LOAD_ERROR;

    fn_write process_write_numbers_to_file = dlsym(lib, "process_write_numbers_to_file");
    if (!rc && !process_write_numbers_to_file)
        rc = LOAD_ERROR;
    
    fn_memory_all memory_allocate = dlsym(lib, "memory_allocate");
    if (!memory_allocate)
        rc = LOAD_ERROR;
    
    fn_find_neg find_negative = dlsym(lib, "find_negative");
    if (!rc && !find_negative)
        rc = LOAD_ERROR;

    fn_key key = dlsym(lib, "key");
    if (!rc && !key)
        rc = LOAD_ERROR;

    fn_cmp comparator = dlsym(lib, "comparator");
    if (!rc && !comparator)
        rc = LOAD_ERROR;
    
    fn_memory_deallocate memory_deallocate = dlsym(lib, "memory_deallocate");
    if (!rc && !memory_deallocate)
        rc = LOAD_ERROR;

    if (!rc)
    {
        int *pb_dst;
        int *pe_dst;
        int *pb_negative = find_negative(pb_src, pe_src);

        if (!pb_negative)
            pb_negative = (int *) pe_src;

        int new_len = pb_negative - pb_src;
        if (!rc)
            rc = memory_allocate(&pb_dst, new_len);

        if (!rc) 
            rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
        if (!rc)
        {
            mysort(pb_dst, pe_dst - pb_dst, sizeof(int), comparator);
            rc = process_write_numbers_to_file(fname, pb_dst, pe_dst);
        }
        memory_deallocate(&pb_dst);
    }
    return rc;
}