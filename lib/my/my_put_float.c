/*
** EPITECH PROJECT, 2023
** my_put_float
** File description:
** my_put_float
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

static char round_exclusion(double num, long long int *int_part)
{
    *int_part = num > 0 ? *int_part + 1 : *int_part - 1;
    return '0';
}

static int my_round(int precision, double *decimal_part, int i)
{
    int digit = 0;

    if (i == (precision - 1) && (int)(*decimal_part * 10.0) > 5)
        digit = (int)(*decimal_part + 0.5);
    else
        digit = (int)(*decimal_part + 0.1);
    return digit;
}

static int my_put_float2(double num, int precision,
    long long int int_part, char *str_dec)
{
    int digit = 0;
    double decimal_part = num - int_part;

    if (precision > 0) {
        if (decimal_part < 0)
            decimal_part *= -1;
        for (int i = 0; i < precision; i++) {
            decimal_part *= 10.0;
            digit = my_round(precision, &decimal_part, i);
            str_dec[i] = ((digit + '0') <= '9') ? digit + '0' :
            round_exclusion(num, &int_part);
            decimal_part -= digit;
        }
    }
    return int_part;
}

int my_put_float(double num, int precision)
{
    int count = 0;
    long long int int_part = (long long int)num;
    char *str_dec = NULL;

    str_dec = malloc(sizeof(char) * (8 + 1));
    int_part = my_put_float2(num, precision, int_part, str_dec);
    if ((int_part == 0 && num < 0) || (num == 0 && 1.0 / num < 0))
        my_putchar('-');
    count += my_put_nbr(int_part);
    if (precision != 0)
        count += my_putchar('.');
    count += my_putstr(str_dec);
    free(str_dec);
    return count;
}
