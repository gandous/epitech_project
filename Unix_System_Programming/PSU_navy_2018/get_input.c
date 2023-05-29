/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** get_input
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy.h"

char *get_input(void)
{
    char *buff;
    size_t size = 0;

    if ((buff = malloc(sizeof(char) * 4)) == NULL)
        return (NULL);
    buff[3] = '\0';
    mputstr("attack: \033[3m");
    size = read(0, buff, 3);
    mputstr("\033[0m");
    if (size <= 0)
        return (NULL);
    else if (size < 3 || buff[2] != '\n') {
        mputstr("wrong position\n");
        free(buff);
        buff = get_input();
    }
    return (buff);
}

int verif_input(char *input)
{
    if (input[0] < 'A' || input[0] > 'H') {
        mputstr("wrong position\n");
        return (ERROR);
    }
    if (input[1] < '1' || input[1] > '8') {
        mputstr("wrong position\n");
        return (ERROR);
    }
    return (SUCCESS);
}