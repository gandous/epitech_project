/*
** EPITECH PROJECT, 2018
** find biggest square
** File description:
** find he biggest square at the coor given as arguements
*/

#include "bsq.h"

int find_big_square(char **map, file_size_t *fsize, array_pos_t *pos, int size)
{
    int nb_rows = fsize->height;
    int nb_cols = fsize->width;
    int row = pos->y;
    int col = pos->x;
    int is_square = is_square_of_size(map, row, col, size);

    while (is_square == 1 && nb_rows > row + size) {
        size += 1;
        is_square = is_square_of_size(map, row, col, size);
    }
    if (is_square == 1) {
        if (nb_rows == row + size || col + size < nb_cols)
            return (size);
        else
            return (size - 1);
    } else
        return (size - 1);
}
