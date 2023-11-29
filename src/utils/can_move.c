/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** can_moove.c
*/

#include <stdbool.h>
#include "sokoban.h"

bool player_can_move(map_t *map, int row, int col)
{
    int dest_row = map->player.row + row;
    int dest_col = map->player.col + col;
    int next_row = dest_row + row;
    int next_col = dest_col + col;

    if (map->player.row + row < 0 || map->player.row + row >= map->row ||
            map->player.col + col < 0 || map->player.col + col >= map->col)
        return false;
    if (map->map[dest_row][dest_col].content == '#')
        return false;
    if (map->map[dest_row][dest_col].content == 'X') {
        if ((next_row >= 0 && next_row < map->row && next_col >= 0 &&
        next_col < map->col) && (map->map[next_row][next_col].content == ' ' ||
        map->map[next_row][next_col].content == 'O')) {
            return true;
        }
        return false;
    }
    return true;
}
