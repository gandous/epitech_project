/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print a string
*/

#include <unistd.h>
#include "bsq.h"

void my_putstr(char const *str, int size)
{
    write(1, str, size);
}
