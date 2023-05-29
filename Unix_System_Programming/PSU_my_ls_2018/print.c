/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** print
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int size = 0;

    for ( ; str[size] != '\0' ; size += 1);
    return (size);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
