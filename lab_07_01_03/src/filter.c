#include "../inc/functions.h"
#include "../inc/functions.h"
#include "../inc/filter.h"

int get_new_size(const int *pb_src, const int *pe_src)
{
    int n = pe_src - pb_src;

    for (int *cur = (int*)pb_src; cur < pe_src; cur++)
        if (*cur < 0)
            n = cur - pb_src;
    
    return n;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src || !pb_dst || !pe_dst || pb_src >= pe_src)
        return POINTER_ERR;

    int n = get_new_size(pb_src, pe_src);

    if (n == 0)
        return FILTER_ERR;

    int rc = create_dynamic_array(pb_dst, n);

    if (rc)
        return rc;

    *pe_dst = *pb_dst + n;

    for (int *cur_dst = *pb_dst, *cur_src = (int*)pb_src; cur_dst < *pe_dst; cur_dst++, cur_src++)
        *cur_dst = *cur_src;

    return rc;
}