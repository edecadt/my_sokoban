/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** parse.c
*/

#include <stddef.h>
#include <malloc.h>
#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

void init_element(map_t *map, int i, int j, char c)
{
    map->map[i][j].content = c;
    if (c == 'P') {
        map->player.row = i;
        map->player.col = j;
    }
    if (c == 'X') {
        map->nb_boxes++;
    }
    if (c == 'O') {
        map->nb_storages++;
    }
}

void parse_original(map_t *map, char **map_array)
{
    map->original_map = malloc(sizeof(cell_t *) * map->row);
    for (int i = 0; i < map->row; i++) {
        map->original_map[i] = malloc(sizeof(cell_t) * map->col);
        for (int j = 0; j < map->col; j++) {
            map->original_map[i][j] = (j < my_strlen(map_array[i])) ?
            map->map[i][j] : map->original_map[i][j];
        }
    }
}

void parse_map(map_t *map, char *buffer)
{
    char **map_array = my_str_to_word_array(buffer, "\n");

    map->buffer = buffer;
    for (int i = 0; map_array[i] != NULL; i++) {
        map->row++;
        map->col = (map->col < my_strlen(map_array[i])) ?
        my_strlen(map_array[i]) : map->col;
    }
    map->map = malloc(sizeof(cell_t *) * map->row);
    for (int i = 0; i < map->row; i++) {
        map->map[i] = malloc(sizeof(cell_t) * map->col);
        for (int j = 0; j < map->col; j++) {
            map->map[i][j].content = (j < my_strlen(map_array[i])) ?
            map_array[i][j] : ' ';
            map->map[i][j].row = i;
            map->map[i][j].col = j;
            init_element(map, i, j, map->map[i][j].content);
        }
    }
    parse_original(map, map_array);
}
