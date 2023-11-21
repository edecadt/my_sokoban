/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** player
*/

#include <my_sokoban.h>
#include <stddef.h>

int is_on_storage(Map *map, int x, int y)
{
    int target_x = map->player_pos.x + x;
    int target_y = map->player_pos.y + y;

    for (int i = 0; i < map->num_storage; i++) {
        if (map->storage_pos[i].x == target_x &&
            map->storage_pos[i].y == target_y) {
            return 1;
        }
    }
    return 0;
}

static void check_for_loose_final(Map* map, int *loose, int i, int j)
{
    int num = 0;

    if (map->map[i][j] == 'X' && !is_on_storage(map, j, i)) {
        if (map->map[i + 1][j] == '#')
            num++;
        if (map->map[i - 1][j] == '#')
            num++;
        if (map->map[i][j + 1] == '#')
            num++;
        if (map->map[i][j - 1] == '#')
            num++;
        if (num > 1)
            (*loose)++;
    }
}

static void check_for_loose(Map *map)
{
    int loose = 0;

    for (int i = 0; map->map[i] != NULL; i++)
        for (int j = 0; map->map[i][j]; j++)
            check_for_loose_final(map, &loose, i, j);
    if (loose == map->num_storage)
        map->exit_code = 1;
}

void move_player_part_two(Map* map, int target_x, int target_y, int now)
{
    if (map->map[target_y][target_x] == ' ' ||
        map->map[target_y][target_x] == 'O') {
        map->map[target_y][target_x] = 'P';
        if (map->is_on_storage && !now) {
            map->map[map->player_pos.y][map->player_pos.x] = 'O';
            map->is_on_storage = 0;
        } else
            map->map[map->player_pos.y][map->player_pos.x] = ' ';
        map->player_pos.x = target_x;
        map->player_pos.y = target_y;
    }
    check_for_loose(map);
}

void move_player(Map *map, int x, int y)
{
    int target_x = map->player_pos.x + x;
    int target_y = map->player_pos.y + y;
    int now = 0;

    if (map->map[target_y][target_x] == 'X') {
        if (map->map[target_y + y][target_x + x] == ' ' ||
            map->map[target_y + y][target_x + x] == 'O') {
            map->map[target_y + y][target_x + x] = 'X';
            map->map[target_y][target_x] = ' ';
        }
    }
    if (map->map[target_y][target_x] == 'O') {
        now = 1;
        map->is_on_storage = 1;
    }
    move_player_part_two(map, target_x, target_y, now);
}
