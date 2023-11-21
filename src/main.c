/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main
*/

#include "my.h"
#include "my_sokoban.h"
#include <unistd.h>

int main(const int ac, const char **av)
{
    if (ac != 2)
        return 84;
    if (is_help(av[1]))
        display_help_text();
    return 0;
}
