/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int a = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    if (a > __INT_MAX__)
        return 0;
    return (a * my_compute_power_rec(a, p - 1));
}
