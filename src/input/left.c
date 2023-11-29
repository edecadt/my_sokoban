/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** left.c
*/

#include <ncurses.h>
#include "sokoban.h"

void key_left(map_t *map)
{
    if (player_can_move(map, 0, -1)) {
        move_player(map, -1, 0);
    }
}
