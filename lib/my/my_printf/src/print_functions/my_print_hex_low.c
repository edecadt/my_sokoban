/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_hex_low
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <stddef.h>

static char *base_final(unsigned int nbr, char const *base, char *str)
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

static char *base(unsigned int nbr, char const *base)
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
    return base_final(nbr, base, str);
}

static void my_print_hex_low_debut(unsigned long long *hex_low, va_list list,
    my_printf_t printf_struct)
{
    switch (printf_struct.length[0]) {
        case 'j':
            *hex_low = (intmax_t)va_arg(list, intmax_t);
            break;
        case 'z':
            *hex_low = (ssize_t)va_arg(list, ssize_t);
            break;
        case 'Z':
            *hex_low = (ssize_t)va_arg(list, ssize_t);
            break;
        case 't':
            *hex_low = (ptrdiff_t)va_arg(list, ptrdiff_t);
            break;
        default:
            *hex_low = va_arg(list, unsigned int);
            break;
    }
}

static void my_print_hex_low_final(unsigned long long *hex_low,
    va_list list, my_printf_t printf_struct)
{
    switch (printf_struct.length[0]) {
        case 'h':
            if (printf_struct.length[1] == 'h')
                *hex_low = (unsigned char)va_arg(list, unsigned int);
            else
                *hex_low = (unsigned short)va_arg(list, unsigned int);
            break;
        case 'l':
            if (printf_struct.length[1] == 'l')
                *hex_low = va_arg(list, unsigned long long);
            else
                *hex_low = va_arg(list, unsigned long);
            break;
        case 'q':
            *hex_low = (unsigned char)va_arg(list, unsigned int);
            break;
        default:
            my_print_hex_low_debut(hex_low, list, printf_struct);
    }
}

static void flag_format(my_printf_t printf_struct, int *len_w,
    char *str)
{
    if (printf_struct.width > 0 && printf_struct.flag_align != 1 &&
        printf_struct.flag_zero != 1)
        while (*len_w < printf_struct.width) {
            (*len_w) += my_putchar(' ');
        }
    if (printf_struct.flag_sign == 1)
        (*len_w) += my_putchar('+');
    if (printf_struct.width > 0 && printf_struct.flag_zero == 1
    && printf_struct.flag_align != 1)
        while (*len_w < printf_struct.width) {
            (*len_w) += my_putchar('0');
        }
    if (printf_struct.flag_hashtag == 1)
        (*len_w) += my_putstr("0x");
    my_putstr(str);
    if (printf_struct.width > 0 && printf_struct.flag_align == 1)
        while (*len_w < printf_struct.width) {
            (*len_w) += my_putchar(' ');
        }
}

int my_print_hex_low(va_list list, my_printf_t printf_struct)
{
    unsigned long long number;
    char *str = 0;
    int len = 0;
    int len_w = 0;

    my_print_hex_low_final(&number, list, printf_struct);
    str = base(number, "0123456789abcdef");
    if (str != NULL) {
        len = my_strlen(str);
        len_w = len;
        if (printf_struct.flag_sign == 1)
            len_w++;
        flag_format(printf_struct, &len_w, str);
        free(str);
        return len_w;
    } else {
        return -1;
    }
}
