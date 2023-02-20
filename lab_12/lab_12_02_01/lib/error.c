#include "../inc/error.h"

void show_error(int rc)
{
    switch (rc)
    {
        case INVALID_INPUT:
            printf("Input invalid\n");
            break;
        case OPEN_FILE_ERROR:
            printf("Can't OPEN file\n");
            break;
        case DATA_ERROR:
            printf("Data invalid\n");
            break;
        case MEMORY_ERROR:
            printf("Cant allocate memory\n");
            break;
        case POINTER_ERROR:
            printf("Pointer for filter invalid\n");
            break;
        case READ_FILE_ERROR:
            printf("Cant read number from file\n");
            break;
        case WRITE_FILE_ERROR:
            printf("Can't write number to file\n");
            break;
        default:
            break;
    }
}
