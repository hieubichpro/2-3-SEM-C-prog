#include "file_work.h"

void strdel(char *str, char pattern)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == pattern)
        {    
            str[i] = '\0';
        }
    }
}

int read_line(char *str, FILE *f)
{
    int rc = OK;
    
    if (fgets(str, STRING_MAX  + 1, f) == NULL)
    {
        rc = ferror(f) ? ERR_READ_FILE : END_FILE; 
    }
    else if (!strchr(str, '\n'))
    {
        if (strlen(str) == STRING_MAX + 1)
            rc = ERR_DATA; 
    }
    else 
        strdel(str, '\n'); // function
    return rc;
}

int convert_str_to_double(char *str, double *num)
{
    int rc = OK;
    char *ptr;
    *num = strtod(str, &ptr);

    if (strlen(ptr) || *num < 1e-15)
        rc = ERR_DATA;
    return rc;
}

int get_double(double *num, FILE *f, int str_max)
{

    char buf[str_max + 1];

    int rc = read_line(buf, f);

    if (rc == END_FILE || convert_str_to_double(buf, num) != OK)
        return ERR_DATA;

    return rc;
}

int read_each_item(item *a, FILE *f)
{
    int rc = OK;
    memset(a, 0, sizeof(item));

    rc = read_line(a->title, f);
    if (rc != OK)
        return rc;

    rc = get_double(&a->weight, f, STRING_MAX);
    if (rc != OK)
        return ERR_WEIGHT;

    rc = get_double(&a->volume, f, STRING_MAX);
    if (rc != OK)
        return ERR_VOLUME;

    return rc;
}

int read_all_items(item *array, int *cnt, int size_arr_max, FILE *f)
{
    int rc = OK;

    for (*cnt = 0 ;(rc = read_each_item(array + *cnt, f)) == OK && *cnt <= size_arr_max; (*cnt)++)

    if (cnt > size_arr_max)
        rc = ARRAY_SIZE_ERROR;
        
    if (rc == END_FILE && *cnt > 0)
        rc = OK;

    return rc;
}

int open_file_and_read_items(item *array, int *cnt, char *fname, int size_arr_max)
{
    FILE *f;
    if (check_open_file(&f, fname) != 0)
        return ERR_OPEN_FILE;

    int rc = read_all_items(array, cnt, ARRAY_MAX, f);
    fclose(f);
    
    return rc;
}