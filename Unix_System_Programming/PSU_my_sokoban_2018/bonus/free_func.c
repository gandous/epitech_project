/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** all function to free all element
*/

#include <stdlib.h>
#include "my_sokoban.h"

void free_2d_string(char **array)
{
    for (int i = 0 ; array[i] != NULL ; i += 1) {
        free(array[i]);
    }
    free(array);
}

void map_data_free(map_t *data)
{
    free_2d_string(data->map);
    free_2d_string(data->save);
    free(data->pos);
    free(data);
}