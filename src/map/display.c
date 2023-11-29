/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** display.c
*/

#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

void display_map(map_t *map)
{
    for (int i = 0; i < map->row; i++) {
        for (int j = 0; j < map->col; j++) {
            printw("%c", map->map[i][j].content);
        }
        printw("\n");
    }
}
