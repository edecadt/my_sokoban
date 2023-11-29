/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban.c
*/

#include <sys/stat.h>
#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

static int help_text(void)
{
    my_printf("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file "
    "representing the warehouse map, containing '#' for walls,\n\t  "
    "'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
    return 0;
}

int sokoban(int argc, char **argv)
{
    map_t map;
    struct stat sb;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    if (argc != 2)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        return help_text();
    map = load_map(argv[1]);
    game_loop(&map);
    free_map(&map);
    endwin();
    return 0;
}
