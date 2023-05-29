/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** Create the matrix and free they
*/

#include <string.h>
#include <stdlib.h>

int size_col(int nb_char)
{
    if (nb_char == 1)
        return (1);
    if (nb_char <= 4)
        return (2);
    if (nb_char <= 9)
        return (3);
    exit(84);
}

int **fill_key_matrix(char *str, int *col)
{
    int **matrix = NULL;
    int nb_char = strlen(str);

    *col = size_col(nb_char);
    matrix = malloc(sizeof(int **) * *col);
    for (int i = 0 ; i < *col ; i++) {
        matrix[i] = malloc(sizeof(int *) * *col);
        for (int ii = 0 ; ii < *col ; ii++)
            matrix[i][ii] = 0;
    }
    for (int i = 0 ; i < nb_char ; i++)
        matrix[i / *col][i % *col] = str[i];
    return (matrix);
}

int **fill_matrix(char *str, int col)
{
    int **matrix = NULL;
    int nb_char = strlen(str);
    
    matrix = malloc(sizeof(int **) * (nb_char / col + 1));
    for (int i = 0 ; i <= nb_char / col ; i++) {
        matrix[i] = malloc(sizeof(int *) * col);
        for (int ii = 0 ; ii < col ; ii++)
            matrix[i][ii] = 0;
    }
    for (int i = 0 ; i < nb_char ; i++)
        matrix[i / col][i % col] = str[i];
    return (matrix);
}

void free_matrix(int **matrix, int size)
{
    for (int i = 0 ; i < size ; i += 1)
        free(matrix[i]);
    free(matrix);
}
