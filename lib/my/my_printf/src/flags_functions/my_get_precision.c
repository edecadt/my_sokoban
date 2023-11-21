/*
** EPITECH PROJECT, 2023
** Epitech CPool mu_printf
** File description:
** my_get_precision
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int my_get_precision(my_printf_t printf_struct)
{
    char *str = printf_struct.percent_str;
    char *start = NULL;

    while (*str) {
        if (*str == '.') {
            start = str;
            break;
        }
        str++;
    }
    if (start)
        return my_getnbr(start + 1);
    return 6;
}
