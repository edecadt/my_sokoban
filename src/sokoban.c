/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Main function
*/

#include <my_sokoban.h>
#include <sys/stat.h>

static int read_arg(Map *map, char *arg)
{
    struct stat st;

    if (is_help(arg)) {
        display_help();
        return 1;
    }
    if (stat(arg, &st) == -1)
        map->exit_code = 84;
    init_map(map, arg);
    return 0;
}

int sokoban(const int ac, char **av)
{
    Map map;

    map.exit_code = 0;
    if (ac != 2)
        return 84;
    if (read_arg(&map, av[1]) == 1)
        return 0;
    if (map.exit_code == 84)
        return 84;
    ncurses_loop(&map);
    return 0;
}
