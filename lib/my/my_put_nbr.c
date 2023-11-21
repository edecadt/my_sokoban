/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int display_overflow(int nb, int *char_count)
{
    if (nb <= -2147483647) {
        my_putchar('-');
        my_put_nbr(214748364);
        my_putchar('8');
        *char_count += 2;
        return 1;
    }
    if (nb >= 2147483647) {
        my_put_nbr(214748364);
        my_putchar('8');
        *char_count += 1;
        return 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    int char_count = 0;

    if (display_overflow(nb, &char_count) == 1) {
        return char_count;
    }
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
        char_count++;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
        char_count++;
        return char_count;
    } else {
        char_count += my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
        char_count++;
    }
    return char_count;
}
