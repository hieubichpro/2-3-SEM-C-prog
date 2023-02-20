#include "../inc/process_sta.h"

void sort_and_write_without_filter(char *fname, int *pb_src, int *pe_src)
{
    mysort(pb_src, pe_src - pb_src, sizeof(int), comparator);
    process_write_numbers_to_file(fname, pb_src, pe_src);
}

int sort_and_write_with_filter(char *fname, int *pb_src, int *pe_src)
{
    int *pb_dst;
    int *pe_dst;
    int *pb_negative = find_negative(pb_src, pe_src);

    if (!pb_negative)
        pb_negative = (int *) pe_src;

    int new_len = pb_negative - pb_src;
    int rc = memory_allocate(&pb_dst, new_len);

    if (!rc) 
        rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    if (!rc)
    {
        mysort(pb_dst, pe_dst - pb_dst, sizeof(int), comparator);
        rc = process_write_numbers_to_file(fname, pb_dst, pe_dst);
    }
    memory_deallocate(&pb_dst);
    
    return rc;
}