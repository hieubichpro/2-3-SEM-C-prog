#include "my_funcs.h"

int main(int argc, char **argv)
{
    int arr_size = 0;
    arr_items arr;
    string fname = "";
    string substr = "";
    
    int status = analyze_args(argc, argv, fname, substr);

    if (status != OK)
        return status;

    status = get_data(arr, &arr_size, fname);
        
    if (status != OK)
        return status;

    if (argc == 2)
        bubble_sort(arr, arr_size);
        
    print_inform(arr, arr_size, argc, substr);
    
    return OK;
}
