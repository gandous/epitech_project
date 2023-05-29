/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** display usage
*/

#include <string.h>
#include <stdio.h>

void print_usage(void)
{
    printf("USAGE\n");
    printf("    ./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("    message     a message, made of ASCII characters\n");
    printf("    key         the encryption key, made of ASCII characters\n");
    printf("    flag        0 for the message to be encrypted, 1 to be decrypted\n");
}

void print_key_matrix(int **matrix, int col)
{
    printf("Key matrix:\n");
    for (int i = 0 ; i < col ; i++) {
        for (int ii = 0 ; ii < col ; ii++) {
            printf("%d", matrix[i][ii]);
            if (ii < col - 1)
                printf("\t");
        }
        printf("\n");
    }
    printf("\n");
}

void print_encrypted_matrix(char *str, int **matrix, int nb_col)
{
    int size = strlen(str);
    
    printf("Encrypted message:\n");
    for (int row = 0 ; row <= (size - 1) / nb_col ; row++) {
        for (int col = 0 ; col < nb_col ; col++) {
            printf("%i", matrix[row][col]);
            if (row < (size - 1) / nb_col || col < nb_col - 1)
                printf(" ");
        }
    }
    printf("\n");
}
