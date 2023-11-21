/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_decimale
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>


static void my_print_dec_debut(unsigned long long *dec, va_list list,
    my_printf_t printf_struct)
{
    switch (printf_struct.length[0]) {
        case 'j':
            *dec = (intmax_t)va_arg(list, intmax_t);
            break;
        case 'z':
            *dec = (ssize_t)va_arg(list, ssize_t);
            break;
        case 'Z':
            *dec = (ssize_t)va_arg(list, ssize_t);
            break;
        case 't':
            *dec = (ptrdiff_t)va_arg(list, ptrdiff_t);
            break;
        default:
            *dec = va_arg(list, unsigned int);
            break;
    }
}

static void my_print_dec_final(unsigned long long *dec,
    va_list list, my_printf_t printf_struct)
{
    switch (printf_struct.length[0]) {
        case 'h':
            if (printf_struct.length[1] == 'h')
                *dec = (unsigned char)va_arg(list, unsigned int);
            else
                *dec = (unsigned short)va_arg(list, unsigned int);
            break;
        case 'l':
            if (printf_struct.length[1] == 'l')
                *dec = va_arg(list, unsigned long long);
            else
                *dec = va_arg(list, unsigned long);
            break;
        case 'q':
            *dec = (unsigned char)va_arg(list, unsigned int);
            break;
        default:
            my_print_dec_debut(dec, list, printf_struct);
    }
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

int my_print_decimal(va_list list, my_printf_t printf_struct)
{
    unsigned long long dec = 0;
    int len = 0;
    int len_w = 0;
    char *dec_str;

    my_print_dec_final(&dec, list, printf_struct);
    dec_str = my_num_to_str((long long)dec);
    len = my_strlen(dec_str);
    len_w = len;
    flag_format(printf_struct, &len_w, dec_str);
    free(dec_str);
    return len_w;
}
