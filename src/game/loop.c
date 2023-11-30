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
    int rows;
    int cols;

    while (key != 27) {
        clear();
        getmaxyx(stdscr, rows, cols);
        handle_input(map, key);
        check_game(map);
        if (cols >= map->col && rows >= map->row)
            display_map(map);
        else
            mvprintw(rows / 2, 0, "Please enlarge the terminal");
        key = getch();
        refresh();
    }
}
