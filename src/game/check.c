/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** check_game.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

static bool is_box_on_storage(map_t *map, int i, int j)
{
    if (map->map[i][j].content == 'X' &&
    map->original_map[i][j].content == 'O')
        return true;
    return false;
}

static bool is_box_stuck(map_t *map, int i, int j)
{
    if (map->map[i][j].content == 'X' && map->map[i][j + 1].content == '#'
        && map->map[i + 1][j].content == '#')
        return true;
    if (map->map[i][j].content == 'X' && map->map[i][j - 1].content == '#'
        && map->map[i + 1][j].content == '#')
        return true;
    if (map->map[i][j].content == 'X' && map->map[i][j - 1].content == '#'
        && map->map[i - 1][j].content == '#')
        return true;
    if (map->map[i][j].content == 'X' && map->map[i][j + 1].content == '#'
        && map->map[i - 1][j].content == '#')
        return true;
    return false;
}

void check_game(map_t *map)
{
    int stuck_boxes = 0;
    int boxes_on_storage = 0;

    for (int i = 0; i < map->row; i++)
        for (int j = 0; j < map->col; j++) {
            stuck_boxes += is_box_stuck(map, i, j);
            boxes_on_storage += is_box_on_storage(map, i, j);
        }
    if (stuck_boxes == map->nb_boxes) {
        endwin();
        exit(1);
    }
    if (boxes_on_storage == map->nb_storages) {
        endwin();
        exit(0);
    }
}
