/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** create, calc...
*/

#include <stdlib.h>
#include "architect.h"

float **create_matrix(int x, int y)
{
    float **matrix;

    matrix = malloc(sizeof(float **) * (x));
    for (int i = 0 ; i < x ; i++)
        matrix[i] = malloc(sizeof(float *) * (y));
    for (int i = 0 ; i < x ; i += 1)
        for (int ii = 0 ; ii < y ; ii += 1)
            matrix[i][ii] = 0;
    return (matrix);
}

void free_matrix(float **matrix, int height)
{
    for (int i = 0; i < height ; i++)
        free(matrix[i]);
    free(matrix);
}

float calc_row_col(float **matrix1, float **matrix2, int row, int col)
{
    float result = 0;

    for (int i = 0 ; i < 3 ; i++)
        result += matrix1[row][i] *  matrix2[i][col];
    return (result);
}

float **calc_matrix_final(float **matrix_3x3_final, float **matrix_xy)
{
    float **result = create_matrix(3, 1);

    for (int row = 0 ; row < 3 ; row++)
        result[row][0] = calc_row_col(matrix_3x3_final, matrix_xy, row, 0);
    return (result);
}

float **calc_matrix(float **matrix1, float **matrix2)
{
    float **result = create_matrix(3, 3);

    for (int row = 0 ; row < 3 ; row ++)
        for (int col = 0 ; col < 3 ; col++)
            result[row][col] = calc_row_col(matrix1, matrix2, row, col);
    return (result);
}
