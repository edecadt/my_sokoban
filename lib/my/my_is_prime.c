/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int i;

    if (nb == 0 || nb == 1)
        return 0;
    if (nb < 0)
        return 0;
    for (i = 2; i < nb - 1; i++) {
        if (i == nb)
            return 1;
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
