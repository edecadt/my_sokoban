/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Header
*/

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

typedef struct {
    int x;
    int y;
} vector2i;

typedef struct {
    char **map;
    char *filepath;
    int num_storage;
    int is_on_storage;
    int exit_code;
    vector2i player_pos;
    vector2i *box_pos;
    vector2i *storage_pos;
} Map;

int sokoban(int ac, char **av);
int is_help(const char *str);
void display_help(void);
int init_map(Map *map, char *file);
char *fs_read_file(const char *filepath);
int ncurses_loop(Map *map);
void display_map(Map *map);
void move_player(Map *map, int x, int y);

#endif //MY_SOKOBAN_H
