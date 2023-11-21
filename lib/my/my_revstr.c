/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    char temp_str;
    int len = my_strlen(str);
    int j = len - 1;

    for (int i = 0; i < j; i++) {
        temp_str = str[i];
        str[i] = str[j];
        str[j] = temp_str;
        j--;
    }
    return str;
}
