/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** verif_stick
*/

#include <stdlib.h>

int verif_sitck(char *line, int stick)
{
    int stick_find = 0;

    for (int i = 0 ; line[i] != '\0' && line[i] != '\n' ; i += 1)
        if (line[i] == '|')
        stick_find += 1;
    if (stick_find >= stick)
        return (1);
    else
        return (0);
}

void remove_stick(char *line, int stick)
{
    int index = 0;

    for ( ; line[index] != '|' ; index += 1);
    for ( ; line[index] != ' ' && line[index] != '*' ; index += 1);
    index -= 1;
    for ( ; stick > 0 ; stick -= 1, index -= 1)
        line[index] = ' ';
}

int count_reaming_stick(char **map)
{
    int stick = 0;

    for (int i = 0 ; map[i] != NULL ; i += 1) {
        for (int ii = 0 ; map[i][ii] != '\0' ; ii += 1)
            (map[i][ii] == '|') ? stick += 1 : 0;
    }
    return (stick);
}

int sitck_on_line(char *line)
{
    int stick = 0;

    if (line == NULL)
        return (0);
    for (int i = 0 ; line[i] != '\0' ; i += 1) {
        if (line[i] == '|')
            stick += 1;
    }
    return (stick);
}