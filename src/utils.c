/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** utils
*/

#include <unistd.h>
#include "my_sokoban.h"

int is_help(const char *str)
{
    if (str[0] == '-' && str[1] == 'h' && str[2] == '\0')
        return 1;
    return 0;
}

void display_help(void)
{
    write(1, "USAGE\n\t./my_sokoban\nDESCRIPTION\n\tmap file "
    "representing the warehouse map, containing '#' for walls,"
    "\n\t    'P' for the player, 'X' for boxes and 'O' for "
    "storage locations.\n", 170);
}
