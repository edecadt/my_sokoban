/*
** EPITECH PROJECT, 2023
** my_showstr
** File description:
** my_showstr
*/

#include "my.h"

void display_hex_for_showstr(const char *str, int i)
{
    my_putchar('\\');
    if (str[i] < 16) {
        my_putchar('0');
    }
    my_putnbr_base(str[i], "0123456789abcdef");
}

int my_showstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126) {
            my_putchar(str[i]);
        } else {
            display_hex_for_showstr(str, i);
        }
        i++;
    }
    return 0;
}
