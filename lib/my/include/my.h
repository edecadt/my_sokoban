/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H

int my_putchar(char c);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, const char *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(const char *str);
int my_showmem(void);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int mini_printf(const char *format, ...);
char *my_strdup(char const *src);
char *my_putnbr_base(int nbr, char const *base);
int my_put_float(double num, int precision);
char *my_strchr(char *str, char c);
char **my_str_to_word_array(char *str, const char *separator);
int get_num_of_char(char *str, char character);

typedef struct my_printf_s {
    char char_type;
    int char_count;
    char *length;
    char *percent_str;
    int precision;
    int flag_sign;
    int flag_align;
    int flag_zero;
    int flag_hashtag;
    int width;
} my_printf_t;

struct format_func {
    char format_char;
    int (*function)(va_list, my_printf_t);
};

int my_printf(char *format, ...);
int my_print_arg(my_printf_t printf_struct, va_list list);
void *my_get_params(char *format, va_list list);
int my_print_char(va_list list, my_printf_t printf_struct);
int my_print_number(va_list list, my_printf_t printf_struct);
int my_print_string(va_list list, my_printf_t printf_struct);
int my_print_percent(va_list list, my_printf_t printf_struct);
int my_print_hex_low(va_list list, my_printf_t printf_struct);
int my_print_hex_up(va_list list, my_printf_t printf_struct);
int my_print_octal(va_list list, my_printf_t printf_struct);
int my_print_decimal(va_list list, my_printf_t printf_struct);
int my_print_nb_sci_low(va_list list, my_printf_t printf_struct);
int my_print_nb_sci_up(va_list list, my_printf_t printf_struct);
int my_print_float(va_list list, my_printf_t printf_struct);
int my_print_pointer(va_list list, my_printf_t printf_struct);
int my_print_nb_stock(va_list list, int char_count);
void my_get_flags(my_printf_t *printf_struct);
int my_get_precision(my_printf_t printf_struct);
char *my_get_length(my_printf_t printf_struct);
char *my_num_to_str(long long int nb);
char *my_float_to_str(long double num, int precision);

#endif
