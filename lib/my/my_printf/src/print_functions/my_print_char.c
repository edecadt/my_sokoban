/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_char
*/

#include "my.h"

int my_print_char(va_list list, my_printf_t printf_struct)
{
    int len_w = 1;

    if (printf_struct.width && printf_struct.flag_align != 1)
        while (len_w < printf_struct.width) {
            my_putchar(' ');
            len_w++;
        }
    my_putchar(va_arg(list, int));
    if (printf_struct.width && printf_struct.flag_align == 1)
        while (len_w < printf_struct.width) {
            my_putchar(' ');
            len_w++;
        }
    return len_w;
}
