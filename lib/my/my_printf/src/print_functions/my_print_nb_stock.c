/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_nb_stock
*/

#include "my.h"

int my_print_nb_stock(va_list list, int char_count)
{
    int *count = va_arg(list, int *);

    *count = char_count;
    return 0;
}
