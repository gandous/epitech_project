/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** error gestion
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "cipher.h"

void print_error(char *str)
{
    write(2, str, strlen(str));
    exit (84);
}

int verif_number(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (-1);
    }
    return (0);
}

void check_crypted(int argc, char **argv)
{
    int action = 0;


    action = atoi(argv[3]);
    if (verif_number(argv[3]) == -1)
        print_error("Unknow flag, use -h for more info\n");
    if (action == 0) {

    } else if (action == 1) {
        if (verif_number(argv[1]) == -1)
            print_error("Encrypted message should only contain numbers, use -h for more info\n");
    } else {
        print_error("Unknow flag, flag should be 0 or 1, use -h for more info\n");
    }
}

void error_gestion(int argc, char **argv)
{
    if (argc == 1 && argv[0][0] == '-' && argv[0][1] == 'h')
        print_usage();
    if (argc > 4)
        print_error("Too much arguments use -h for more information\n");
    if (argc < 4)
        print_error("Not enought argument use -h for more information\n");
    check_crypted(argc, argv);
}