#include "../inc/IO.h"

int check_file_io(FILE **f_in, char *fname, char *mode)
{
    int rc = OK;
    *f_in = fopen(fname, mode);
    if (*f_in == NULL)
    {
        rc = OPEN_FILE_ERROR;
    }
    return rc;
}

int count_elements(int *count, int end_file, FILE *f_in)
{
    int rc = OK;
    int temp;
    *count = 0;
    while ((rc = fscanf(f_in, "%d", &temp)) == 1)
        *count += 1;
    
    if (rc != end_file || *count == 0)
        rc = DATA_ERROR;
    else 
        rc = OK;
    rewind(f_in);
    return rc;
}

int memory_allocate(int **pb_src, int len)
{
    int rc = OK;

    *pb_src = (int *) malloc(sizeof(int) * len);
    if (*pb_src == NULL)
        rc = MEMORY_ERROR;
    return rc;
}

void memory_deallocate(int **pb_src)
{
    if (!(*pb_src))
    {
        free(*pb_src);
        *pb_src = NULL;
    }
}

int read_number(int *pos, FILE *f)
{
    int rc = OK;

    if (fscanf(f, "%d", pos) != 1)
        rc = READ_FILE_ERROR;
    
    return rc;
}

int read_numbers(int *pb_src, int *pe_src, FILE *f)
{
    int rc = OK;

    for (int *ptr_i = pb_src; rc == OK && ptr_i < pe_src; ptr_i++)
        if (read_number(ptr_i, f))
        {
            rc = READ_FILE_ERROR;
        }
    return rc;
}

int process_read_numbers_from_file(int **pb_src, int **pe_src, char *fname)
{
    int rc = OK;

    FILE *file_in;
    rc = check_file_io(&file_in, fname, "r");
    if (rc != OK)
        return rc; 

    int count;
    if (!(rc = count_elements(&count, END_FILE, file_in)) && !(rc = memory_allocate(pb_src, count)))
    {
        *pe_src = *pb_src + count;
        rc = read_numbers(*pb_src, *pe_src, file_in);
        if (rc != OK)
            memory_deallocate(pb_src);
    }

    fclose(file_in);
    return rc;    
}

int write_number(FILE *f, int number)
{
    int rc = OK;
    if (fprintf(f, "%d ", number) < 0)
        rc = WRITE_FILE_ERROR;
    return rc;
}

int write_numbers(FILE *f, int *pb_src, int *pe_src)
{
    int rc = OK;
    
    for (int *ptr_i = pb_src; rc == OK && ptr_i < pe_src; ptr_i++)
        if (write_number(f, *ptr_i))
            rc = WRITE_FILE_ERROR;
    return rc;
}

int process_write_numbers_to_file(char *fname, int *pb_src, int *pe_src)
{
    int rc = OK;

    FILE *file_out;
    rc = check_file_io(&file_out, fname, "w");
    if (rc != OK)
        return rc;
    
    rc = write_numbers(file_out, pb_src, pe_src);

    fclose(file_out);
    return rc;
}
