/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_string
*/

#include "my.h"
#include <stddef.h>
#include <unistd.h>

int my_print_string(va_list list, my_printf_t printf_struct)
{
    char *str = va_arg(list, char *);
    int len = my_strlen(str);
    int len_w = len;

    if (printf_struct.width > 0 && printf_struct.flag_align != 1)
        while (len_w < printf_struct.width) {
            my_putchar(' ');
            len_w++;
        }
    if (printf_struct.precision != -1 && printf_struct.precision <= len)
        len = printf_struct.precision;
    my_putstr(str);
    if (printf_struct.width > 0 && printf_struct.flag_align == 1)
        while (len_w < printf_struct.width) {
            my_putchar(' ');
            len_w++;
        }
    return len_w;
}
