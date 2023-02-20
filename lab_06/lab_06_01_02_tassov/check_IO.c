#include "check_IO.h"

int check_open_file(FILE **f, char *fname)
{
    int rc = OK;
    *f = fopen(fname, "r");
    if (!(*f))
    {
        fprintf(stderr, "Could not open '%s' due to error: %s\n", fname, strerror(errno));
        rc = ERR_OPEN_FILE; 
    }
    return rc;
}

int analyze_args(int argc, char **argv, char *filename, char *sub_string)
{
    if (argc < LOWER_LIMIT_ARGC || argc > UPPER_LIMIT_ARGC)
        return ARGS_ERROR;

    strcpy(filename, argv[1]);
    if (argc == 3)
    {
        if (check_sub_string(sub_string) != OK)
            return ERR_SIZE_SUBSTR;
        strcpy(sub_string, argv[2]);
    }
    
    return OK;
}

int check_sub_string(char *sub_string)
{
    int rc = OK;
    if (strlen(sub_string) > SUB_STRING_SIZE)
        rc = ERR_SIZE_SUBSTR;
    return rc;
}