/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** init.c
*/

#include <stddef.h>
#include "sokoban.h"

void init_map(map_t *map)
{
    map->row = 0;
    map->col = 0;
    map->nb_boxes = 0;
    map->nb_storages = 0;
    map->player.row = 0;
    map->player.col = 0;
}
