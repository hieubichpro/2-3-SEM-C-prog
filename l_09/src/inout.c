#include "../inc/inout.h"

int read_object_len(int *obj_len, FILE *f)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, f) != -1)
        (*obj_len) ++;
    free(line);

    if (*obj_len % 3)
        return INVALID_SIZE;
    *obj_len /= 3;
    
    fseek(f, 0, SEEK_SET);
    return OK;
}

int read_name(char **name, FILE *f)
{
    *name = NULL;
    size_t len = 0;
    if (getline(name, &len, f) == -1)
        return ERROR_INPUT;
    return OK;
}

int read_object(object_t *obj_arr, int len, FILE *f)
{
    for (int i = 0; i != len; i++)
    {
        int rc = read_name(&((obj_arr + i)->name), f);
        if (rc)
        {
            delete(obj_arr, i + 1);
            return rc;
        }

        rc = fscanf(f, "%f\n", &((obj_arr + i)->macca));
        if (rc != 1 || (obj_arr + i)->macca <= 0)
        {
            delete(obj_arr, i + 1);
            return ERROR_INPUT;
        }

        rc = fscanf(f, "%f\n", &((obj_arr + i)->volumn));
        if (rc != 1 || (aobj_arr + i)->volumn <= 0)
        {
            delete(obj_arr, i + 1);
            return INVALID_INPUT;
        }
    }

    return OK;
}

void print_object(object_t *obj_arr, int len, int argc, char **argv)
{
    for (int i = 0; i < len; i++)
    {
        if (argc == MIN_ARGC || strcmp(argv[2], "ALL") == OK)
        {
            printf("%s", (obj_arr + i)->name);
            printf("%.6f\n", (obj_arr + i)->macca);
            printf("%.6f\n", (obj_arr + i)->volumn);
        }
        else if (strncmp(argv[2], obj_arr[i].name, strlen(argv[2])) == OK)
        {
            printf("%s", (obj_arr + i)->name);
            printf("%.6f\n", (obj_arr + i)->macca);
            printf("%.6f\n", (obj_arr + i)->volumn);
        }
    }
}

void delete(object_t *obj_arr, int index)
{
    for (int i = 0; i < index; i++)
        free((obj_arr + i)->name);
    free(obj_arr);
}