/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** free.c
*/

#include <stddef.h>
#include <malloc.h>
#include "sokoban.h"

void free_map(map_t *map)
{
    if (map->buffer != NULL)
        free(map->buffer);
    if (map->map != NULL) {
        for (int i = 0; i < map->row; i++)
            free(map->map[i]);
        free(map->map);
    }
    if (map->original_map != NULL) {
        for (int i = 0; i < map->row; i++)
            free(map->original_map[i]);
        free(map->original_map);
    }
}
