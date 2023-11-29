/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** move_player.c
*/

#include <ncurses.h>
#include "sokoban.h"

void move_player(map_t *map, int x, int y)
{
    if (player_can_move(map, y, x)) {
        if (map->map[map->player.row + y][map->player.col + x].content == 'X')
            move_box(map, x, y);
        map->map[map->player.row][map->player.col].content = ' ';
        if (map->original_map[map->player.row][map->player.col].content == 'O')
            map->map[map->player.row][map->player.col].content = 'O';
        map->player.row += y;
        map->player.col += x;
        map->map[map->player.row][map->player.col].content = 'P';
    }
}
