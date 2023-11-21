/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_get_flags
*/

#include "my.h"

static void get_width(char **str, my_printf_t *printf_struct)
{
    if (**str >= '1' && **str <= '9') {
        printf_struct->width = my_getnbr(*str);
        while (**str >= '0' && **str <= '9') {
            (*str)++;
        }
    } else
        printf_struct->width = 0;
}

void my_get_flags(my_printf_t *printf_struct)
{
    char *str = printf_struct->percent_str;

    while (*str) {
        if (*str == '+') {
            printf_struct->flag_sign = 1;
        }
        if (*str == '-') {
            printf_struct->flag_align = 1;
        }
        if (*str == '0') {
            printf_struct->flag_zero = 1;
        }
        if (*str == '#')
            printf_struct->flag_hashtag = 1;
        get_width(&str, printf_struct);
        str++;
    }
}
