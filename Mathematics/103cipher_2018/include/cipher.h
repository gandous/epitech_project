/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** header for 103cipher
*/

#define SUCCESS          0
#define ERROR            84

#ifndef CIPHER_H_
#define CIPHER_H_

int cipher(int argc, char **argv);
int **fill_key_matrix(char *str, int *col);
int **fill_matrix(char *str, int col);
void print_key_matrix(int **matrix, int col);
void print_usage(void);
void error_gestion(int argc, char **argv);
void print_error(char *str);
int **encrypted_matrix(char *str, int **matrix, int **key_matrix, int size_col);
void free_matrix(int **matrix, int size);
void print_encrypted_matrix(char *str, int **matrix, int nb_col);

#endif
