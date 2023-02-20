#include "../inc/filter.h"

int *find_negative(const int *pb_src, const int *pe_src)
{
    int *pb_neg = NULL;
    for (int *i = (int *) pb_src; !pb_neg && i < pe_src; i++)
        if (*i < 0)
            pb_neg = i;

    return pb_neg;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{   
    if (!pb_src || !pe_src || !pb_dst || !pe_dst)
        return POINTER_ERROR;

    if (pb_src >= pe_src)
        return POINTER_ERROR;
    
    int *pb_negative = find_negative(pb_src, pe_src);

    if (!pb_negative)
        pb_negative = (int *) pe_src;

    int new_len = pb_negative - pb_src;
    if (new_len == 0)
        return DATA_ERROR;

    int rc = OK;
    if (!rc)
    {
        memcpy(*pb_dst, pb_src, sizeof(int) * new_len);
        *pe_dst = *pb_dst + new_len;
    }
    return rc;
}
