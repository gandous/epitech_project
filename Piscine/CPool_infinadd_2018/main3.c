/*
** EPITECH PROJECT, 2018
** hello
** File description:
** main 3
*/

#include "my.h"

int start_neg(char *nb)
{
    if (nb[0] == '-') {
        return (1);
    }
    return (0);
}

void dipslay_signe(char *nb)
{
    if (nb[0] == '-') {
        my_putchar('-');
    }
}

int next_sous(char nb1, char nb2, long size2, int retenu)
{
    int nombre1 = nb1;
    int nombre2;

    if (size2 < 0 || nb2 == '-') {
        nombre2 = 48;
    } else {
        nombre2 = nb2;
    }
    return (nombre1 - nombre2 - retenu);
}

int str_len(char *str)
{
    int size = 0;
    int index = 0;

    while (str[index] == '0' || str[index] == '-') {
        index++;
    }
    while (str[index] != '\0') {
        index += 1;
        size += 1;
    }
    return (size);
}
