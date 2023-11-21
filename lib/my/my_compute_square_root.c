/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    if (nb == 1)
        return 1;
    for (int i = 0; i < nb; i++) {
        if (i > __INT_MAX__)
                return 0;
        if (i * i == nb && (i != nb))
            return i;
    }
    return 0;
}
