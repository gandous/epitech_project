/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** load_boat_pos
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "navy.h"

static int verif_one_pos(char *boat, int i)
{
    int x_diff = boat[i+2] - boat[i+5];
    int y_diff = boat[i+3] - boat[i+6];

    x_diff < 0 ? x_diff *= -1 : x_diff;
    y_diff < 0 ? y_diff *= -1 : y_diff;
    if (x_diff == boat[i] - '0' - 1 && y_diff == 0)
        return (SUCCESS);
    else if (y_diff == boat[i] - '0' - 1 && x_diff == 0)
        return (SUCCESS);
    return (ERROR);
}

static int verif_pos(char *boat)
{
    char boat_detect[5] = "0000";

    for (int i = 0 ; boat[i] != '\0' ; i += 1) {
        if (boat[i + 1] == '\0')
            break;
        if (boat[i] - '2' < 0 || boat[i] - '2' > 4)
            return (ERROR);
        boat_detect[boat[i] - '2'] = '1';
        if (verif_one_pos(boat, i) == ERROR)
            return (ERROR);
        i += 7;
    }
    for (int index = 0 ; boat_detect[index] != '\0' ; index += 1)
        if (boat_detect[index] == '0')
            return (ERROR);
    return (SUCCESS);
}

static char **generate_map(char *buffer)
{
    char **temp;

    if ((temp = malloc(sizeof(char*) * 9)) == NULL)
        return (NULL);
    for (int i = 0 ; i <= 8 ; i += 1)
        temp[i] = NULL;
    for (int ind = 0 ; ind < 8 ; ind++)
        if ((temp[ind] = malloc(sizeof(char) * 9)) == NULL)
            return (NULL);
    for (int i = 0 ; i < 8 ; i++) {
        for (int ii = 0 ; ii < 8 ; ii++)
            temp[i][ii] = '.';
        temp[i][8] = '\0';
    }
    place_boat(temp, buffer);
    return (temp);
}

char **load_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[33];
    int size = 0;
    char **map = NULL;

    if (fd == -1)
        return (NULL);
    if ((size = read(fd, buffer, 32)) != 32)
        return (NULL);
    close(fd);
    buffer[size] = '\0';
    if (verif_pos(buffer) == ERROR)
        return (NULL);
    if ((map = generate_map(buffer)) == NULL)
        return (NULL);
    return (map);
}
