/*
** EPITECH PROJECT, 2018
** mem alloc 2d array
** File description:
** alloc memory for a 2d array
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **rows = NULL;
    char *cols;

    rows = malloc(sizeof(char *) * (nb_rows + 1));
    if (rows == NULL)
        exit(84);
    for (int i = 0 ; i < nb_rows ; i += 1) {
        cols = malloc(sizeof(char) * (nb_cols + 1));
        if (cols == NULL)
            exit(84);
        rows[i] = cols;
    }
    return (rows);
}
