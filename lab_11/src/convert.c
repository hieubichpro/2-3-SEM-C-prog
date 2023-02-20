#include "../inc/convert.h"

int get_base(char ch)
{
    return (ch == 'd') ? 10 : 16;
}

int get_len_number(unsigned long int number, int base)
{
    int len = 0; 

    do
    {
        number /= base;
        len++;
    } while (number);
    
    return len;
}

char *get_alphabet(int base)
{
    return (base == 10) ? D_ALPHABET : X_ALPHABET;
}

int convert_long_number_to_string(char *dest, long int number, char type_base, size_t max_size)
{
    int count = 0;
    int base = get_base(type_base);

    int str_l = (!dest) ? 0 : my_strlen(dest);

    if (base == 10 && number < 0)
    {
        count = add_char(dest, '-', max_size);
        number *= -1;
    }

    unsigned long int u_number = (unsigned long int) number;

    count += get_len_number(u_number, base);

    if (dest)
    {
        char *alphabet = get_alphabet(base);
        int temp_len = (str_l + count) > max_size - 1 ? max_size - 1 : (str_l + count);
        do
        {
            dest[--temp_len] = alphabet[u_number % base];

            u_number /= base;
        } while (u_number);
    }
    return count;
}