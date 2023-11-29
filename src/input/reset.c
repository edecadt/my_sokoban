/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** reset.c
*/

#include <stddef.h>
#include <malloc.h>
#include "sokoban.h"
#include "my.h"

void key_reset(map_t *map)
{
    printf(map->buffer);
    analyse_map(map, map->buffer);
    parse_map(map, map->buffer);
}
