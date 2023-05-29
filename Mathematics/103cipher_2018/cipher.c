/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** cipher
*/

#include <stdlib.h>
#include "cipher.h"

int cipher(int argc, char **argv)
{
    int **matrix = NULL;
    int **key_matrix = NULL;
    int col = 0;

    error_gestion(argc, argv);
    key_matrix = fill_key_matrix(argv[2], &col);
    matrix = fill_matrix(argv[1], col);
    print_key_matrix(key_matrix, col);
    if (argv[3][0] == '0') {
        matrix = encrypted_matrix(argv[1], matrix, key_matrix, col);
        print_encrypted_matrix(argv[1], matrix, col);
    }// else {
    //decrypted_matrix;
    //print_decrypted_matrix;
    return (SUCCESS);
}
