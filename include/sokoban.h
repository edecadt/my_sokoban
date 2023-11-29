/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban.h
*/

#ifndef MY_SOKOBAN_MY_SOKOBAN_H
    #define MY_SOKOBAN_MY_SOKOBAN_H
    #include <stdbool.h>

typedef struct {
    int row;
    int col;
    char content;
} cell_t;

typedef struct {
    int row;
    int col;
} pos_t;

typedef struct {
    int row;
    int col;
    char *buffer;
    cell_t **map;
    cell_t **original_map;
    pos_t player;
    int nb_boxes;
    int nb_storages;
} map_t;

int sokoban(int ac, char **av);
void init_map(map_t *map);
map_t load_map(char *filepath);
void analyse_map(map_t *map, const char *buffer);
void parse_map(map_t *map, char *buffer);
void display_map(map_t *map);
void game_loop(map_t *map);
void handle_input(map_t *map, int key);
void key_up(map_t *map);
void key_down(map_t *map);
void key_right(map_t *map);
void key_left(map_t *map);
void key_reset(map_t *map);
bool player_can_move(map_t *map, int row, int col);
void move_player(map_t *map, int x, int y);
void move_box(map_t *map, int x, int y);
char get_element_on_pos(map_t *map, int row, int col);
void check_game(map_t *map);
void free_map(map_t *map);
#endif //MY_SOKOBAN_MY_SOKOBAN_H
