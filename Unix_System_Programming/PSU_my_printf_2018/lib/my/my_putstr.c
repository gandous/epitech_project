/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print a string
*/

#include <unistd.h>
#include "myprintf.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
