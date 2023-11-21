/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** my_sort_int_array
*/

#include "my.h"

void my_sort_int_array_final(int *array, int size, int index)
{
    int j;

    for (j = 0; j < size - index - 1; j++) {
        if (array[j] > array[j + 1]) {
            my_swap(&array[j], &array[j + 1]);
            break;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        my_sort_int_array_final(array, size, i);
    }
}
