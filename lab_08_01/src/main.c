#include "../inc/func_IO.h"
#include "../inc/func_matrix.h"
#include "../inc/error.h"

int main(void)
{   
    matrix a, b;

    int rc = read_matrices(&a, &b);

    if (rc)
    {
        message_error(rc);
        return rc;
    }

    reduce_matrix(&a);
    reduce_matrix(&b);

    rc = fill_in_to_become_squre(&a, &b);

    if (rc)
    {
        message_error(rc);
        return rc;
    }

    rc = matrix_exponentiation(&a, &b);

    if (rc)
    {
        message_error(rc);
        return rc;
    }

    matrix res;

    rc = get_result(&res, &a, &b);

    if (rc)
    {
        message_error(rc);
        return rc;
    }

    print_matrix(&res);

    free_mem(a.matrix, a.r);
    free_mem(b.matrix, b.r);
    free_mem(res.matrix, res.r);

    return rc;
}
