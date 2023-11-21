/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** my_getnbr
*/

int convert_string_to_int(const char *str, int is_neg)
{
    int number = 0;
    int a = 0;
    int max = __INT_MAX__;
    int digit;
    int y = max / 10;
    int x = max % 10;

    while (str[a] >= '0' && str[a] <= '9' && str[a] != '\0') {
        digit = str[a] - '0';
        if ((is_neg == 1 && (number > y || (number == y && digit > x))) ||
            (is_neg == -1 && (number > y || (number == y && digit - 1 > x)))) {
            return 0;
        }
        number = number * 10 + (str[a] - '0');
        a++;
    }
    return number * is_neg;
}

int my_getnbr(char const *str)
{
    int a = 0;
    int is_neg = 1;

    while (str[a] == '+' || str[a] == '-') {
        if (str[a] == '-')
            is_neg = -is_neg;
        a++;
    }
    return convert_string_to_int(&str[a], is_neg);
}
