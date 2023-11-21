/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "my_sokoban.h"

static int get_num_of_storage(Map *map)
{
    int num = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            num += (map->map[i][j] == 'O');
        }
    }
    return num;
}

static void get_player_position_two(Map *map, vector2i *pos, int i, int j)
{
    if (map->map[i][j] == 'P') {
        pos->x = j;
        pos->y = i;
    }
}

static vector2i get_player_position(Map *map)
{
    vector2i pos = {0, 0};

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            get_player_position_two(map, &pos, i, j);
        }
    }
    return pos;
}

static void get_boxes_position_two(Map *map, vector2i *pos, int i, int j)
{
    int index = 0;

    if (map->map[i][j] == 'X') {
        pos[index].x = j;
        pos[index].y = i;
        index++;
    }
}

static vector2i *get_boxes_positions(Map *map)
{
    vector2i *pos = malloc(sizeof(vector2i) * 2);

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            get_boxes_position_two(map, pos, i, j);
        }
    }
    return pos;
}

static void get_storages_position_two(Map *map, vector2i *pos, int i, int j)
{
    int index = 0;

    if (map->map[i][j] == 'O') {
        pos[index].x = j;
        pos[index].y = i;
        index++;
    }
}

static vector2i *get_storages_positions(Map *map)
{
    vector2i *pos = malloc(sizeof(vector2i) * 2);

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            get_storages_position_two(map, pos, i, j);
        }
    }
    return pos;
}

int init_map(Map *map, char *file)
{
    char *buff = fs_read_file(file);

    map->filepath = file;
    if (buff == NULL)
        return 84;
    map->map = my_str_to_word_array(buff, "\n");
    map->num_storage = get_num_of_storage(map);
    map->player_pos = get_player_position(map);
    map->box_pos = get_boxes_positions(map);
    map->storage_pos = get_storages_positions(map);
    return 0;
}

void display_map(Map *map)
{
    for (int i = 0; map->map[i] != NULL; i++) {
        printw("%s\n", map->map[i]);
    }
}
