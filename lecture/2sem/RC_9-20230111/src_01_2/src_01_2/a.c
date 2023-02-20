// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     int *a = calloc(5, sizeof(int));
//     free(a);
//     a = NULL;
//     int i;
//     for (i = 0; i < 5; i++)
//         printf("%d ", *(a + i));
//     printf("%d\n", *(a + 1));
//     printf("%p\n", (void*)a);
//     return 0;
// }

// int main()
// {
//    char str[10];
 
//    /* Stored in read only part of data segment */
//    str = "GfG";    
 
//    /* Problem:  trying to modify read only memory */
// //    str[1] = 'n';
//    printf("%s\n", str);
// //    *(str + 1) = 'n';
//    return 0;
// }

#include <stdio.h>

#define N 5

int main(void)
{
    // char str[N] = "June";
    
    // for (int i = 0; i < N + 10; i++)
    //     printf("%d ", str[i]);
    int nums[N];

    for (int i = 0; i < N + 1; i++)
        scanf("%d", &nums[i]);

    for (int i = 0; i < N + 1; i++)
        printf("%d ", nums[i]);

    return 0;
}
