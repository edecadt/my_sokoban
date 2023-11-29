/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** handle.c
*/

#include <curses.h>
#include "sokoban.h"
#include "my.h"

void handle_input(map_t *map, int key)
{
    if (key == KEY_LEFT)
        key_left(map);
    if (key == KEY_RIGHT)
        key_right(map);
    if (key == KEY_UP)
        key_up(map);
    if (key == KEY_DOWN)
        key_down(map);
    if (key == 32)
        key_reset(map);
}
