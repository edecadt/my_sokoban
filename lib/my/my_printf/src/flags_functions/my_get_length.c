/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_get_length
*/

#include "my.h"

char *my_get_length(my_printf_t printf_struct)
{
    char *str = printf_struct.percent_str;

    while (*str) {
        if (*(str + 1) == 'h' && *str == 'h')
            return "hh\0";
        if (*str == 'h')
            return "h\0";
        if (*(str + 1) == 'l' && *str == 'l')
            return "ll\0";
        if (*str == 'l')
            return "l\0";
        if (*str == 'L')
            return "L\0";
        if (*str == 'z')
            return "z\0";
        str++;
    }
    return "\0";
}
