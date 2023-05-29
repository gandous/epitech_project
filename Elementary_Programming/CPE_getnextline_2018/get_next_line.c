/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *conc_str(char *start, char *end, int *index_s)
{
    int size1 = 0;
    int size2 = *index_s;
    int index = 0;
    char *temp = NULL;

    if (start != NULL)
        for ( ; start[size1] != '\0' && start != NULL ; size1 += 1);
    for ( ; end[size2] != '\0' && end[size2] != '\n' ; size2 += 1);
    temp = malloc(sizeof(char) * (size1 + size2 + 1));
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; i < size1 + size2 ; i += 1)
        temp[i] = '\0';
    temp[size1 + size2] = '\0';
    if (start != NULL)
        for ( ; start[index] != '\0' ; index += 1)
            temp[index] = start[index];
    for ( ; *index_s < size2 ; *index_s += 1, index += 1)
        temp[index] = end[*index_s];
    free(start);
    return (temp);
}

char *load_ligne(char *save, int *index, int *size, int fd)
{
    char *buff = NULL;

    while (save[*index] != '\n' && *size > 0) {
        buff = conc_str(buff, save, index);
        if (buff == NULL)
            return (NULL);
        if (save[*index] == '\0') {
            *size = read(fd, save, READ_SIZE);
            save[*size] = '\0';
            *index = 0;
        }
    }
    return (buff);
}

char *generate_back(void)
{
    char *buff = NULL;

    buff = malloc(sizeof(char) * 1);
    if (buff == NULL)
        return (NULL);
    buff[0] = '\0';
    return (buff);
}

char *get_next_line(int fd)
{
    char *buff = NULL;
    static int size = 0;
    static char *save = NULL;
    static int index = 0;

    if (fd < 0)
        return (NULL);
    if (save == NULL) {
        save = malloc(sizeof(char) * (READ_SIZE + 1));
        if (save == NULL)
            return (NULL);
        for (int i = 0 ; i < READ_SIZE + 1 ; i += 1)
            save[i] = '\0';
        size = read(fd, save, READ_SIZE);
    }
    buff = load_ligne(save, &index, &size, fd);
    index += 1;
    if (buff == NULL && save[index - 1] == '\n')
        return (generate_back());
    return (buff);
}