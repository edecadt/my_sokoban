/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_printf source file
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static int is_percent_type(char c)
{
    char *valid_chars = "cspdiouxXfFeEgGaAn";

    while (*valid_chars) {
        if (*valid_chars == c)
            return 1;
        valid_chars++;
    }
    return 0;
}

static int is_modulo(char *str)
{
    if (my_strncmp(str, "%%", 2) == 0) {
        return 1;
    }
    return 0;
}

static char *my_get_percent_string(char *str)
{
    char *percent_string = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *start = percent_string;

    while (*str && !is_percent_type(*str)) {
        *percent_string = *str;
        percent_string++;
        str++;
    }
    *percent_string = *str;
    percent_string++;
    *percent_string = '\0';
    return start;
}

static char my_get_char_type(my_printf_t printf_struct)
{
    char *str = printf_struct.percent_str;

    while (*str) {
        if (is_percent_type(*str))
            return *str;
        str++;
    }
    return 0;
}

static void struct_modif(char *format, my_printf_t *printf_struct)
{
    printf_struct->percent_str = my_get_percent_string(&(*format));
    printf_struct->precision = my_get_precision(*printf_struct);
    printf_struct->length = my_get_length(*printf_struct);
    printf_struct->char_type = my_get_char_type(*printf_struct);
    my_get_flags(printf_struct);
}

static void my_percent_is_valid_final(char *str, char *valid_chars,
    int *valid_char_found)
{
    while (*valid_chars) {
        if (*str == *valid_chars) {
            *valid_char_found = 1;
            break;
        }
        valid_chars++;
    }
}

static int my_percent_is_valid(char *str)
{
    char *valid_chars = "cspdiouxXfFeEgGaAn+-0123456789lhztqj.# %";
    int valid_char_found = 0;

    while (*str) {
        if (*str == '%')
            str++;
        my_percent_is_valid_final(str, valid_chars, &valid_char_found);
        if (!valid_char_found) {
            return 0;
        }
        str++;
    }
    return 1;
}

static void reset_struct(my_printf_t *printf_s)
{
    printf_s->char_type = 0;
    printf_s->char_count = 0;
    printf_s->length = 0;
    printf_s->percent_str = 0;
    printf_s->precision = 0;
    printf_s->flag_sign = 0;
    printf_s->flag_align = 0;
    printf_s->flag_zero = 0;
    printf_s->flag_hashtag = 0;
    printf_s->width = 0;
}

static int my_printf_loop(char *format, va_list list)
{
    int char_count = 0;
    my_printf_t printf_struct;

    while (*format) {
        if (is_modulo(format)) {
            char_count += my_putchar('%');
            format += 2;
        }
        if (*format == '%' && my_percent_is_valid(format)) {
            reset_struct(&printf_struct);
            printf_struct.char_count = char_count;
            struct_modif(format, &printf_struct);
            char_count += my_print_arg(printf_struct, list);
            format += my_strlen(printf_struct.percent_str);
        } else {
            char_count += my_putchar(*format);
            format++;
        }
    }
    return char_count;
}

int my_printf(char *format, ...)
{
    va_list list;
    int char_count = 0;

    va_start(list, format);
    char_count = my_printf_loop(format, list);
    va_end(list);
    return char_count;
}
