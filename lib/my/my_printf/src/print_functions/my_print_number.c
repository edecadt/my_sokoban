/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_number
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <stddef.h>

static void my_num_to_str_final(int length, char **str, long long int nb)
{
    int is_neg = 0;

    if (nb < 0) {
        nb = -nb;
        is_neg = 1;
        length++;
    }
    *str = (char *)malloc((length + 1) * sizeof(char));
    (*str)[length] = '\0';
    while (length > 0) {
        --length;
        (*str)[length] = '0' + (nb % 10);
        nb /= 10;
    }
    if (is_neg) {
        (*str)[0] = '-';
    }
}

char *my_num_to_str(long long int nb)
{
    long long int temp = nb;
    int length = 0;
    char *str;

    if (nb == 0) {
        str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    while (temp != 0) {
        temp /= 10;
        length++;
    }
    my_num_to_str_final(length, &str, nb);
    return str;
}

static void flag_format(my_printf_t prt_s, int *len_w,
    char *str)
{
    if (prt_s.width > 0 && prt_s.flag_align != 1 &&
        prt_s.flag_zero != 1)
        while (*len_w < prt_s.width) {
            my_putchar(' ');
            (*len_w)++;
        }
    if (prt_s.flag_sign == 1)
        my_putchar('+');
    if (prt_s.width > 0 && prt_s.flag_zero == 1 && prt_s.flag_align != 1)
        while (*len_w < prt_s.width) {
            my_putchar('0');
            (*len_w)++;
        }
    my_putstr(str);
    if (prt_s.width > 0 && prt_s.flag_align == 1)
        while (*len_w < prt_s.width) {
            my_putchar(' ');
            (*len_w)++;
        }
}

static void my_print_number_debut(long long *number, va_list list,
    my_printf_t printf_struct)
{
    switch (printf_struct.length[0]) {
        case 'j':
            *number = (intmax_t)va_arg(list, intmax_t);
            break;
        case 'z':
            *number = (ssize_t)va_arg(list, ssize_t);
            break;
        case 'Z':
            *number = (ssize_t)va_arg(list, ssize_t);
            break;
        case 't':
            *number = (ptrdiff_t)va_arg(list, ptrdiff_t);
            break;
        default:
            *number = va_arg(list, int);
            break;
    }
}

static void my_print_number_final(long long *number,
    va_list list, my_printf_t printf_struct)
{
    switch (printf_struct.length[0]) {
        case 'h':
            if (printf_struct.length[1] == 'h')
                *number = (char)va_arg(list, int);
            else
                *number = (short)va_arg(list, int);
            break;
        case 'l':
            if (printf_struct.length[1] == 'l')
                *number = va_arg(list, long long);
            else
                *number = va_arg(list, long);
            break;
        case 'q':
            *number = (char)va_arg(list, int);
            break;
        default:
            my_print_number_debut(number, list, printf_struct);
    }
}

int my_print_number(va_list list, my_printf_t prt_s)
{
    long long number = 0;
    int len = 0;
    int len_w = 0;
    char *str;

    my_print_number_final(&number, list, prt_s);
    str = my_num_to_str(number);
    len = my_strlen(str);
    len_w = len;
    if (prt_s.flag_sign == 1)
        len_w++;
    flag_format(prt_s, &len_w, str);
    free(str);
    return len_w;
}
