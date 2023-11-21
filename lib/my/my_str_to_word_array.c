/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <string.h>

static int is_separator(char character, const char *separator)
{
    while (*separator) {
        if (*separator == character)
            return 1;
        separator++;
    }
    return 0;
}

static void get_num_of_word_final(char const **str, const char *separator)
{
    while (**str && !is_separator(**str, separator))
        (*str)++;
}

static int get_num_of_word(char const *str, const char *separator)
{
    int num_of_word = 0;

    while (*str) {
        while (*str && is_separator(*str, separator))
            str++;
        if (*str && !is_separator(*str, separator)) {
            num_of_word++;
            get_num_of_word_final(&str, separator);
        }
    }
    return num_of_word;
}

static int get_size_of_word(char const *str, const char *separator)
{
    int size_of_word = 0;

    while (*str && !is_separator(*str, separator)) {
        size_of_word++;
        str++;
    }
    return size_of_word;
}

char **my_str_to_word_array(char *str, const char *separator)
{
    const int num_of_word = get_num_of_word(str, separator);
    char **word_array = malloc(sizeof(char *) * (num_of_word + 1));
    int size_of_word = 0;
    char *word = str;

    for (int i = 0; i < num_of_word; i++) {
        while (*word && is_separator(*word, separator))
            word++;
        size_of_word = get_size_of_word(word, separator);
        word_array[i] = malloc(sizeof(char) * (size_of_word + 1));
        strncpy(word_array[i], word, size_of_word);
        word_array[i][size_of_word] = '\0';
        word += size_of_word;
    }
    word_array[num_of_word] = NULL;
    return word_array;
}
