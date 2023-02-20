#include "../inc/error.h"

void message_error(int rc)
{
    switch (rc)
    {
        case ERR_INPUT:
            puts("error input\n");
            break;
        case ERR_MEMORY:
            puts("error memory\n");
        default:
            break;
    }
}