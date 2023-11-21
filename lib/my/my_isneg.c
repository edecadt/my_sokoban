/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    my_putchar('\n');
    return 0;
}
