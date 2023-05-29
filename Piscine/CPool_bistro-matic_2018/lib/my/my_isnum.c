/*
** EPITECH PROJECT, 2018
** my_isnum
** File description:
** if num --> 1, else --> 0
*/

int my_isnum(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}
