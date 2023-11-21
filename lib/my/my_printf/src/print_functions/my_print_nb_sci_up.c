/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_nb_sc_up
*/

#include "my.h"
#include <unistd.h>

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

static int my_print_e(int exponent, double num, my_printf_t printf_struct)
{
    char *str = my_float_to_str(num, printf_struct.precision);
    int len = 0;
    int len_w = 0;

    my_strcat(str, "E");
    if (exponent < 0) {
        my_strcat(str, "-");
        exponent = -exponent;
    } else
        my_strcat(str, "+");
    if (exponent < 10)
        my_strcat(str, "0");
    my_strcat(str, my_num_to_str((long long int)exponent));
    len = my_strlen(str);
    len_w = len;
    if (printf_struct.flag_sign == 1)
        len_w++;
    flag_format(printf_struct, &len_w, str);
    return len_w;
}

static int printf_sci_zero(double num, my_printf_t printf_struct)
{
    char *str = my_float_to_str(num, printf_struct.precision);
    int len = 0;
    int len_w = 0;

    my_strcat(str, "E+00");
    len = my_strlen(str);
    len_w = len;
    if (printf_struct.flag_sign == 1)
        len_w++;
    flag_format(printf_struct, &len_w, str);
    return len_w;
}

int my_print_nb_sci_up(va_list list, my_printf_t printf_struct)
{
    double num = va_arg(list, double);
    int exponent = 0;

    if (num == 0.0)
        return printf_sci_zero(num, printf_struct);
    while (num >= 10.0 || num <= -10.0) {
        num /= 10.0;
        exponent++;
    }
    while (num < 1.0 && num > -1.0) {
        num *= 10.0;
        exponent--;
    }
    return my_print_e(exponent, num, printf_struct);
}
