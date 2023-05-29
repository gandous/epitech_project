/*
** EPITECH PROJECT, 2018
** str_cut
** File description:
** cut the first char of a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *str_cut(char *str)
{
    char *rtrn;
    int i = 0;

    rtrn = malloc (sizeof(char *) * my_strlen(str));
    for (i ; str[i + 1] ; i++)
        rtrn[i] = str[i + 1];
    rtrn[i] = '\0';
    return (rtrn);
}
