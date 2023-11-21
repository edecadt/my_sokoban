/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** my_prime_find_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        nb = 0;
    if (nb > __INT_MAX__)
        return 2;
    if (my_is_prime(nb))
        return nb;
    return my_find_prime_sup(nb + 1);
}
