/*
** EPITECH PROJECT, 2018
** str_isfac
** File description:
** detect in a string if there is a factor operator
*/

int str_isfac(char const *str, int i)
{
    switch (str[i]) {
    case '*':
        return (1);
    case '/':
        return (1);
    case '%':
        return (1);
    default:
        return (0);
    }
}
