/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** matrix calcul function
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher.h"

int calc_row_col(int **matrix1, int **matrix2, int row, int col, int size_col)
{
    int result = 0;

    for (int i = 0 ; i < size_col ; i++)
        result += matrix1[row][i] * matrix2[i][col];
    return (result);
}

int **encrypted_matrix(char *str, int **matrix, int **key_matrix, int size_col)
{
    int size = strlen(str);
    int **result_matrix;

    result_matrix = malloc(sizeof(int **) * ((size - 1) / size_col + 1));
    for (int i = 0 ; i <= (size - 1) / size_col ; i++)
        result_matrix[i] = malloc(sizeof(int *) * size_col);
    for (int row = 0 ; row <= (size - 1) / size_col ; row++)
        for (int col = 0 ; col < size_col ; col++)
            result_matrix[row][col] = calc_row_col(matrix, key_matrix, row, col, size_col);
    free_matrix(matrix, size / size_col);
    return (result_matrix);
}
    
