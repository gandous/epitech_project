/*
** EPITECH PROJECT, 2018
** test main
** File description:
** test mzin don't push
*/

#include <stdlib.h>
#include <stdio.h>
#include "bsq.h"

void search_square(char **map, file_size_t *size_file,
array_pos_t *my_pos, square_coord_t *big_sq)
{
    int temp_size = 0;
    if (map[my_pos->y][my_pos->x] != 'o')
        temp_size =  find_big_square(map, size_file, my_pos, big_sq->size);
    if (temp_size >= big_sq->size) {
        if (temp_size > big_sq->size) {
            big_sq->x = my_pos->x;
            big_sq->y = my_pos->y;
            big_sq->size = temp_size;
        }
    }
}

square_coord_t *find_bsq(char **temp, file_size_t *size_file)
{
    int wth = size_file->width;
    int height = size_file->height;
    array_pos_t *pos = NULL;
    square_coord_t *big_s = NULL;

    pos = malloc(sizeof(array_pos_t));
    big_s = malloc(sizeof(square_coord_t));
    if (pos == NULL || big_s == NULL)
        exit(84);
    big_s->x = 0;
    big_s->y = 0;
    big_s->size = 0;
    for (pos->y = 0 ; pos->y <= height - big_s->size - 1 ; pos->y += 1) {
        for (pos->x = 0 ; pos->x <= wth - big_s->size - 1 ; pos->x += 1) {
            search_square(temp, size_file, pos, big_s);
        }
    }
    free(pos);
    return (big_s);
}

int main_bsq(char *path)
{
    file_size_t *s_file = calc_file_size(path);
    char **map = load_2d_array_from_file(path, s_file->height, s_file->width);
    square_coord_t *big_square = NULL;

    big_square = find_bsq(map, s_file);
    replace_map(map, big_square);
    display_map(map, s_file);
    for (int i = 0 ; i < s_file->height ; i ++) {
        free(map[i]);
    }
    free(map);
    free(big_square);
    free(s_file);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        main_bsq(argv[1]);
    } else {
        return (84);
    }
    return (0);
}
