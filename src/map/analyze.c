/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** analyze.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

void analyse_map(map_t *map, const char *buffer)
{
    int nb_player = 0;
    int nb_boxes = 0;
    int nb_storages = 0;

    init_map(map);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'P')
            nb_player++;
        if (buffer[i] == 'X')
            nb_boxes++;
        if (buffer[i] == 'O')
            nb_storages++;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != '#' && buffer[i] != ' ' && buffer[i] != 'P'
            && buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != '\n')
            exit(84);
    }
    if (nb_player != 1 || nb_boxes < nb_storages)
        exit(84);
}
