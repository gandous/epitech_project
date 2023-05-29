/*
** EPITECH PROJECT, 2018
** remove signe
** File description:
** remove the first char of a string if its '-'
*/

#include <stdlib.h>

int my_strlen(char *);

char *char_remove_sign(char *nbr)
{
    char *temp = NULL;
    int size = my_strlen(nbr);

    if (nbr[0] != '-')
        return (nbr);
    temp = malloc(sizeof(char) * size);
    for (int i = 1 ; i < size ; i += 1) {
        temp[i - 1] = nbr[i];
    }
    return (temp);
}
