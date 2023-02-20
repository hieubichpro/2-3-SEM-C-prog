#include "error.h"

void message_error(int rc)
{
    switch (rc)
    {
        case ARGS_ERROR:
            printf("Invalid number of arguments\n");
            break;
        case ERR_SIZE_SUBSTR:
            printf("Substring is too long\n");
            break;
        case ERR_OPEN_FILE:
            printf("File can not open\n");
            break;
        case ERR_DATA:
            printf("Data in file invalid\n");
            break;
        case ERR_WEIGHT:
            printf("Weight in file invalid\n");
            break;
        case ERR_VOLUME:
            printf("Volume in file invalid\n");
            break;  
        default:
            break;
    }
}