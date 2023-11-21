/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_float
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

static void my_int_part(long double num, char **str, int *len)
{
    long long int int_part = (long long int)num;
    char temp;

    if (int_part == 0) {
        (*str)[*len] = '0';
        (*len)++;
    } else {
        while (int_part > 0) {
            (*str)[*len] = '0' + (int_part % 10);
            (*len)++;
            int_part /= 10;
        }
    }
    for (int i = 0; i < *len / 2; i++) {
        temp = (*str)[i];
        (*str)[i] = (*str)[(*len) - 1 - i];
        (*str)[(*len) - 1 - i] = temp;
    }
}

static char *negative_part(int is_negative, int *len, char *str)
{
    char *neg_str = malloc(sizeof(char) * (*len + 2));

    if (is_negative) {
        neg_str[0] = '-';
        for (int i = 0; i < *len; i++) {
            neg_str[i + 1] = str[i];
        }
        neg_str[*len + 1] = '\0';
        free(str);
        return neg_str;
    } else {
        return str;
    }
}

static void my_dec_part(int precision, long double *decimal_part,
    char **str, int *len)
{
    int digit = 0;

    for (int i = 0; i < precision; i++) {
        *decimal_part *= 10;
        digit = (int)*decimal_part;
        (*str)[*len] = '0' + digit;
        (*len)++;
        *decimal_part -= digit;
    }
}

char *my_float_to_str(long double num, int precision)
{
    int is_negative = 0;
    char *str = (char *) malloc(sizeof(char) * 64);
    int len = 0;
    long double decimal_part = 0;

    if (num < 0 || (num == 0 && 1.0 / num < 0)) {
        is_negative = 1;
        num = -num;
    }
    num += 0.5 / my_compute_power_rec(10, precision);
    decimal_part = num - (int) num;
    my_int_part(num, &str, &len);
    decimal_part = num - (int)num;
    str[len] = '.';
    len++;
    my_dec_part(precision, &decimal_part, &str, &len);
    str[len] = '\0';
    return negative_part(is_negative, &len, str);
}

static void flag_format(my_printf_t printf_struct, int *len_w,
    char *str)
{
    if (printf_struct.width > 0 && printf_struct.flag_align != 1 &&
    printf_struct.flag_zero != 1)
        while (*len_w < printf_struct.width) {
            my_putchar(' ');
            (*len_w)++;
        }
    if (printf_struct.flag_sign == 1)
        my_putchar('+');
    if (printf_struct.width > 0 && printf_struct.flag_zero == 1
    && printf_struct.flag_align != 1)
        while (*len_w < printf_struct.width) {
            my_putchar('0');
            (*len_w)++;
        }
    my_putstr(str);
    if (printf_struct.width > 0 && printf_struct.flag_align == 1)
        while (*len_w < printf_struct.width) {
            my_putchar(' ');
            (*len_w)++;
        }
}

int my_print_float(va_list list, my_printf_t printf_struct)
{
    long double long_double_arg = (printf_struct.length[0] == 'L')
    ? va_arg(list, long double) : va_arg(list, double);
    char *str = my_float_to_str(long_double_arg, printf_struct.precision);
    int len = my_strlen(str);
    int len_w = len + (printf_struct.flag_sign ? 1 : 0);

    flag_format(printf_struct, &len_w, str);
    return len_w;
}
