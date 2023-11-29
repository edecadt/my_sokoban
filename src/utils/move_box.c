/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** move_box.c
*/

#include <ncurses.h>
#include "sokoban.h"

void move_box(map_t *map, int x, int y)
{
    if (map->map[map->player.row + y * 2][map->player.col + x * 2].content
        == ' ' || map->map[map->player.row + y * 2][map->player.col + x * 2]
        .content == 'O') {
        map->map[map->player.row + y * 2][map->player.col + x * 2].content
            = 'X';
        map->map[map->player.row + y][map->player.col + x].content = 'P';
        map->map[map->player.row][map->player.col].content = ' ';
    }
}
