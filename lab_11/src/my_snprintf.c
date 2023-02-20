#include "../inc/my_snprintf.h"

int my_snprintf(char *s, size_t size, const char *format, ...)
{
    if (!format)
        return ERROR_DATA;
    
    va_list arg;
    va_start(arg, format);

    size_t str_l = 0;
    
    char *old_format = (char *) format;
    char *new_format = my_strchr(old_format, '%');

    if (s)
        my_memset(s, 0, size);

    for (; new_format; new_format = my_strchr(new_format, '%'))
    {
        str_l += my_strncat(s, old_format, new_format - old_format, size);
        new_format = my_strncat_specifier(s, &str_l, new_format + 1, arg, size);
        old_format = new_format;
    }

    str_l += my_strncat(s, old_format, my_strlen(old_format), size);

    va_end(arg);

    return str_l;
}

char *my_strncat_specifier(char *dest, size_t *str_len, char *spec, va_list arg, size_t max_size)
{
    int count = 0;
    if (*spec == 's')
    {
        char *string = va_arg(arg, char *);
        count = my_strncat(dest, string, my_strlen(string), max_size);
        spec = spec + 1;
    } 
    else if (*spec == 'l')
    {
        count = convert_long_number_to_string(dest, va_arg(arg, long int), *(spec + 1), max_size);
        spec = spec + 2;
    }
    else if (*spec == 'd')
    {
        count = convert_long_number_to_string(dest, va_arg(arg, int), *spec, max_size);
        spec = spec + 1;
    }
    else if (*spec == '%')
    {
        count = add_char(dest, '%', max_size);
        spec = spec + 1;
    }
    else 
    {
        count = add_char(dest, '%', max_size);
    }
    *str_len += count;
    return spec;
}

