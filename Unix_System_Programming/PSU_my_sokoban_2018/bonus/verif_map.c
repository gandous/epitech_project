/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** check if the map is correct for playing
*/

#include "my_sokoban.h"

int is_good_char(char c)
{
    if (c == 'P' || c == 'X' || c == 'O' || c == '#' || c == ' ' || c == '\n')
        return (SUCCES);
    return (ERROR);
}

int verif_ligne(char *ligne, int *perso, int *reaming)
{
    int ii;

    for (ii = 0 ; ligne[ii] != '\0' ; ii += 1) {
        switch (ligne[ii]) {
        case 'P':
            *perso += 1;
            break;
        }
        if (is_good_char(ligne[ii]) != SUCCES)
            return (-1);
    }
    return (ii + 1);
}

int verif_map(map_t *data)
{
    int perso = 0;
    char **map = data->save;
    int temp_width = 0;
    int i;

    data->reaming = 0;
    for (i = 0 ; map[i] != NULL ; i += 1) {
        temp_width = verif_ligne(map[i], &perso, &data->reaming);
        if (temp_width > data->w)
            data->w = temp_width;
        else if (temp_width == -1)
            return (ERROR);
    }
    data->h = i;
    if (box != 0 || perso != 1)
        return (ERROR);
    else
        return (SUCCES);
}