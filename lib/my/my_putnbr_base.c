/*
** EPITECH PROJECT, 2023
** my_putnbr_base
** File description:
** my_putnbr_base
*/

#include <stdlib.h>
#include "my.h"

static char *my_putnbr_base_final(int nbr, char const *base, char *str)
{
    int i = 0;
    int len_base = my_strlen(base);
    int start;
    int end;
    char temp;

    for (; nbr > 0; i++) {
        str[i] = base[nbr % len_base];
        nbr /= len_base;
    }
    str[i] = '\0';
    start = (str[0] == '-') ? 1 : 0;
    end = i - 1;
    for (; start < end; end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
    }
    return str;
}

char *my_putnbr_base(int nbr, char const *base)
{
    int len_base = my_strlen(base);
    char *str;

    str = malloc(sizeof(char) * 12);
    if (len_base < 2) {
        str[0] = '\0';
        return str;
    }
    if (nbr == 0) {
        str[0] = base[0];
        str[1] = '\0';
        return str;
    }
    return my_putnbr_base_final(nbr, base, str);
}
