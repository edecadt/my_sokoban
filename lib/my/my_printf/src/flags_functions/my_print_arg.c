/*
** EPITECH PROJECT, 2023
** Epitech CPool my_printf
** File description:
** my_print_arg
*/

#include "my.h"

struct format_func ptr_func[] = {
    {'c', my_print_char},
    {'s', my_print_string},
    {'i', my_print_number},
    {'d', my_print_number},
    {'x', my_print_hex_low},
    {'X', my_print_hex_up},
    {'o', my_print_octal},
    {'u', my_print_decimal},
    {'e', my_print_nb_sci_low},
    {'E', my_print_nb_sci_up},
    {'f', my_print_float},
    {'F', my_print_float},
    {'g', my_print_float},
    {'G', my_print_float},
    {'p', my_print_pointer}
};

int my_print_arg(my_printf_t printf_struct, va_list list)
{
    char character = printf_struct.char_type;

    for (int i = 0; ptr_func[i].format_char; i++) {
        if (ptr_func[i].format_char == character) {
            return ptr_func[i].function(list, printf_struct);
        }
    }
    if (character == 'n')
        return my_print_nb_stock(list, printf_struct.char_count);
    my_putchar('%');
    my_putchar(character);
    return 2;
}
