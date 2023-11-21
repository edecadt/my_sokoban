/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    if (s1[i] - s2[i] > 0)
        return 1;
    if (s1[i] - s2[i] < 0)
        return -1;
    if (s1[i] - s2[i] == 0)
        return 0;
    return 0;
}
