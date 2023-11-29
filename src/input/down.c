/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** down.c
*/

#include <stdio.h>
#include <ncurses.h>
#include "sokoban.h"

void key_down(map_t *map)
{
    if (player_can_move(map, 1, 0)) {
        move_player(map, 0, 1);
    }
}
