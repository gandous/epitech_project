/*
** EPITECH PROJECT, 2018
** is_square_of_size
** File description:
** return 1 if a square can be found at the position given in argument
*/

int is_space_of_size(char *line, int col, int size)
{
    for (int i = col ; i < col + size ; i += 1) {
        if (line[i] == 'o' || line[i] == '\0'){
            return (0);
        }
    }
    return (1);
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    for (int i = row ; i < row + square_size ; i += 1) {
        if (is_space_of_size(map[i], col, square_size) == 0)
            return (0);
    }
    return (1);
}
