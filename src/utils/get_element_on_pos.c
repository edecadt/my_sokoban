/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get_element_on_pos.c
*/

#include "sokoban.h"

char get_element_on_pos(map_t *map, int row, int col)
{
    return map->original_map[row][col].content;
}
