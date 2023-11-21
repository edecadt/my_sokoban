/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Ncurses
*/

#include <my_sokoban.h>
#include <ncurses.h>

void read_input(Map *map, int key)
{
    if (key == KEY_UP)
        move_player(map, 0, -1);
    if (key == KEY_DOWN)
        move_player(map, 0, 1);
    if (key == KEY_LEFT)
        move_player(map, -1, 0);
    if (key == KEY_RIGHT)
        move_player(map, 1, 0);
    if (key == 32)
        init_map(map, map->filepath);
}

static int check_win(Map *map)
{
    int num = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            num += (map->map[i][j] == 'O');
        }
    }
    if (num == 0)
        return 1;
    return 0;
}

int ncurses_loop(Map *map)
{
    int key = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while (key != 27) {
        clear();
        display_map(map);
        if (check_win(map))
            break;
        key = getch();
        read_input(map, key);
        if (map->exit_code != 0)
            break;
        refresh();
    }
    endwin();
    return map->exit_code;
}
