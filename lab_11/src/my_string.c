#include "../inc/my_string.h"

size_t my_strlen(char const *str)
{
    size_t len = 0;
    for (; str[len]; len++);
    return len;
}

char *my_strchr(char *str, char ch)
{
    for (; *str && *str != ch; str++);

    return (*str != '\0') ? str : NULL; 
}

void *my_memset(void *str, int value, size_t size)
{
    char *ptr = (char *) str;
    
    for (size_t i = 0; i < size; i++, ptr++)
        *ptr = value;
    
    return str;
}

int add_char(char *dest, char ch, size_t max_size)
{
    if (dest)
    {
        dest[my_strlen(dest)] = ch;
    }

    return 1;
}

int my_strncat(char *dest, char *src, int n, size_t max_size)
{
    if (dest)
    {
        int str_l = my_strlen(dest);
        for (int i = 0; i < n && str_l < max_size - 1; i++, str_l++)
            dest[str_l] = src[i];
        dest[str_l] = '\0';
    }

    return n;
}


