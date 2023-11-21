/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Main function
*/

#include <my_sokoban.h>

static void read_arg(Map *map, char *arg)
{
    if (is_help(arg))
        display_help();
    else
        init_map(map, arg);
}

int sokoban(const int ac, char **av)
{
    Map map;

    map.exit_code = 0;
    if (ac != 2)
        return 84;
    read_arg(&map, av[1]);
    ncurses_loop(&map);
    return 0;
}
