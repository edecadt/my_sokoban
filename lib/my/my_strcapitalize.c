/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        if (str[i] >= 97 && str[i] <= 122 && (str[i - 1] == 32 || i == 0))
            str[i] = str[i] - 32;
    }
    return str;
}
