/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strchr
*/

#include <stddef.h>

char *my_strchr(char *str, char c)
{
    while (*str) {
        if (*str == c)
            return str;
        str++;
    }
    return NULL;
}
