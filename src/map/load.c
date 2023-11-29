/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** load.c
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "sokoban.h"

map_t load_map(char *filepath)
{
    map_t map;
    struct stat sb;
    char *buffer;
    ssize_t buffer_size;

    if (stat(filepath, &sb) == -1)
        exit(84);
    if (sb.st_size == 0)
        exit(84);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL)
        exit(84);
    buffer_size = read(open(filepath, 0), buffer, sb.st_size);
    if (buffer_size == -1)
        exit(84);
    buffer[buffer_size] = '\0';
    analyse_map(&map, buffer);
    parse_map(&map, buffer);
    return map;
}
