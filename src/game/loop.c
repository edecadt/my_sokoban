/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_loop.c
*/

#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

void game_loop(map_t *map)
{
    int key = 0;

    while (key != 27) {
        clear();
        handle_input(map, key);
        check_game(map);
        display_map(map);
        key = getch();
        refresh();
    }
}
