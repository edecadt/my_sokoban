/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_ocatl
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <inttypes.h>
#include <stddef.h>

static char *base_final(unsigned long long nbr, char const *base, char *str)
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

static char *base(unsigned long long nbr, char const *base)
{
    int len_base = my_strlen(base);
    char *str;

    str = malloc(sizeof(char) * 12);
    if (str == NULL) {
        return NULL;
    }
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

static void my_print_octal_debut(unsigned long long *octal, va_list list,
    my_printf_t prt_s)
{
    switch (prt_s.length[0]) {
        case 'j':
            *octal = (intmax_t)va_arg(list, intmax_t);
            break;
        case 'z':
            *octal = (ssize_t)va_arg(list, ssize_t);
            break;
        case 'Z':
            *octal = (ssize_t)va_arg(list, ssize_t);
            break;
        case 't':
            *octal = (ptrdiff_t)va_arg(list, ptrdiff_t);
            break;
        default:
            *octal = va_arg(list, unsigned int);
            break;
    }
}

static void my_print_octal_final(unsigned long long *octal,
    va_list list, my_printf_t prt_s)
{
    switch (prt_s.length[0]) {
        case 'h':
            if (prt_s.length[1] == 'h')
                *octal = (unsigned char)va_arg(list, unsigned int);
            else
                *octal = (unsigned short)va_arg(list, unsigned int);
            break;
        case 'l':
            if (prt_s.length[1] == 'l')
                *octal = va_arg(list, unsigned long long);
            else
                *octal = va_arg(list, unsigned long);
            break;
        case 'q':
            *octal = (unsigned char)va_arg(list, unsigned int);
            break;
        default:
            my_print_octal_debut(octal, list, prt_s);
    }
}

static void flag_format(my_printf_t prt_s, int *len_w,
    char *str)
{
    if (prt_s.width > 0 && prt_s.flag_align != 1 && prt_s.flag_zero != 1)
        while (*len_w < prt_s.width)
            (*len_w) += my_putchar(' ');
    if (prt_s.flag_sign == 1)
        (*len_w) += my_putchar('+');
    if (prt_s.width > 0 && prt_s.flag_zero == 1 && prt_s.flag_align != 1)
        while (*len_w < prt_s.width)
            (*len_w) += my_putchar('0');
    if (prt_s.flag_hashtag == 1)
        (*len_w) += my_putchar('0');
    my_putstr(str);
    if (prt_s.width > 0 && prt_s.flag_align == 1)
        while (*len_w < prt_s.width)
            (*len_w) += my_putchar(' ');
}

int my_print_octal(va_list list, my_printf_t prt_s)
{
    unsigned long long number;
    char *str = 0;
    int len = 0;
    int len_w = 0;

    my_print_octal_final(&number, list, prt_s);
    str = base(number, "01234567");
    if (str != NULL) {
        len = my_strlen(str);
        len_w = len;
        if (prt_s.flag_sign == 1)
            len_w++;
        flag_format(prt_s, &len_w, str);
        free(str);
        return len_w;
    } else {
        return -1;
    }
}
