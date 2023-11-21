/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_pointer
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

static char *base_final(unsigned long nbr, char const *base, char *str)
{
    int i = 0;
    int len_base = my_strlen(base);
    int start;
    int end;
    char temp;

    for (; nbr > 0; i++) {
        str[i] = base[nbr % len_base];
        nbr /= len_base;
    }
    str[i] = '\0';
    start = (str[0] == '-') ? 1 : 0;
    end = i - 1;
    for (; start < end; end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
    }
    return str;
}

static char *base(unsigned long nbr, char const *base)
{
    int len_base = my_strlen(base);
    char *str;

    str = malloc(sizeof(char) * 12);
    if (len_base < 2) {
        str[0] = '\0';
        return str;
    }
    if (nbr == 0) {
        str[0] = base[0];
        str[1] = '\0';
        return str;
    }
    return base_final(nbr, base, str);
}

static void flag_format(my_printf_t printf_struct, int *len_w,
    char *str)
{
    if (printf_struct.width > 0 && printf_struct.flag_align != 1 &&
        printf_struct.flag_zero != 1)
        while (*len_w < printf_struct.width) {
            my_putchar(' ');
            (*len_w)++;
        }
    if (printf_struct.flag_sign == 1)
        my_putchar('+');
    my_putstr("0x");
    if (printf_struct.width > 0 && printf_struct.flag_zero == 1
    && printf_struct.flag_align != 1)
        while (*len_w < printf_struct.width) {
            my_putchar('0');
            (*len_w)++;
        }
    my_putstr(str);
}

int my_print_pointer(va_list list, my_printf_t printf_struct)
{
    int len = 0;
    int len_w = 0;
    unsigned long pointer_value = va_arg(list, unsigned long);
    char *result = base(pointer_value, "0123456789abcdef");

    if (*result == '0')
        return my_putstr("(nil)");
    len = my_strlen(result) + 2;
    len_w = len;
    flag_format(printf_struct, &len_w, result);
    if (printf_struct.width > 0 && printf_struct.flag_align == 1)
        while (len_w < printf_struct.width) {
            my_putchar(' ');
            len_w++;
        }
    return len_w;
}
