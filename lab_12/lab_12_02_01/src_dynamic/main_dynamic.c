#include <dlfcn.h>
#include "../inc/process.h"

int main(int argc, char **argv)
{
    void *lib = dlopen("libarr.so", RTLD_LAZY);
    if (!lib)
        printf("vi sao\n");
    if (!lib)
        return OPEN_FILE_ERROR;
    
    int rc = OK;
    fn_read process_read_numbers_from_file = dlsym(lib, "process_read_numbers_from_file");
    fn_memory_deallocate memory_deallocate = dlsym(lib, "memory_deallocate");

    if (argc == 3 || (argc == 4 && !strcmp(argv[3], "f")))
    {   
        int *pb_src;
        int *pe_src;
        rc = process_read_numbers_from_file(&pb_src, &pe_src, *(argv + 1));
        if (rc == OK)
        {
            if (argc == 3)
            { 
                rc = sort_and_write_without_filter(*(argv + 2), pb_src, pe_src, lib);
            }
            else 
            {
                rc = sort_and_write_with_filter(*(argv + 2), pb_src, pe_src, lib);
            }
        }
        memory_deallocate(&pb_src);
    }
    else 
        rc = INVALID_INPUT;
    dlclose(lib);
    return rc;
}