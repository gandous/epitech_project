/*
** EPITECH PROJECT, 2018
** str_isfac_sum
** File description:
** detect in a string an operator
*/

int str_isfac_sum(char const *str, int i)
{

    switch (str[i]) {
    case '+':
        return (1);
    case '-':
        return (1);
    case '*':
        return (1);
    case '%':
        return (1);
    case '/':
        return (1);
    case '\0':
        return (1);
    default:
        return (0);
    }
    return (0);
}
