/*
** EPITECH PROJECT, 2018
** infinity addition
** File description:
** infinadd
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"
#include "main2.h"
#include "main3.h"

void soustraction(char *nb_max, char *nb_min)
{
    long size1 = my_strlen(nb_max) - 1;
    long size2 = my_strlen(nb_min) - 1;
    linked_list *output = NULL;
    int nbtemp = 0;
    int retenu = 0;

    while (condition_while(nb_max, nb_min, size1, size2) == 1) {
        nbtemp = next_sous(nb_max[size1], nb_min[size2], size2, retenu);
        retenu = 0;
        if (nbtemp < 0) {
            nbtemp += 10;
            retenu = 1;
        }
        output = add_element(output, nbtemp + 48);
        size1 -= 1;
        size2 -= 1;
    }
    if (retenu == 1)
        my_putchar('1');
    dipslay_signe(nb_max);
    afficher_list(output);
}

void num_sup2(char *nb1, char *nb2)
{
    int	index =	start_neg(nb1);
    int	index2 = start_neg(nb2);

    while (nb1[index] == '0' && nb2[index2] == '0') {
        index =+ 1;
        index2 += 1;
    }
    while (nb1[index] == nb2[index]) {
        index++;
    }
    if (nb1[index] > nb2[index]) {
        soustraction(nb1, nb2);
    } else {
        soustraction(nb2, nb1);
    }
}


int number_sup(char *nb1, char *nb2)
{
    long size1 = str_len(nb1);
    long size2 = str_len(nb2);

    if (size1 > size2) {
        soustraction(nb1, nb2);
        return (0);
    } else if (size1 < size2) {
        soustraction(nb2, nb1);
        return (0);
    }
    num_sup2(nb1, nb2);
}

void addition(char *nb1, char *nb2)
{
    long size1 = my_strlen(nb1) - 1;
    long size2 = my_strlen(nb2) - 1;
    linked_list *output = NULL;
    int nbtemp = 0;
    int retenu = 0;

    while (condition_while(nb1, nb2, size1, size2) == 1) {
        nbtemp = next_nb(nb1, nb2, size1, size2) + retenu;
        retenu = 0;
        if (nbtemp > 9) {
            nbtemp -= 10;
            retenu = 1;
        }
        output = add_element(output, nbtemp + 48);
        size1 -= 1;
        size2 -= 1;
    }
    if (retenu == 1)
        my_putchar('1');
    afficher_list(output);
}

int main(int argc, char **argv)
{
    int nb_signe;

    if (argc == 3) {
        if (my_str_isnum(argv[1]) != 1 || my_str_isnum(argv[2]) != 1) {
            return (84);
        }
        nb_signe = nb_neg(argv[1], argv[2]);
        if (nb_signe == 2)
            my_putchar('-');
        if (nb_signe == 1) {
            number_sup(argv[1], argv[2]);
            return (0);
        }
        addition(argv[1], argv[2]);
        return (0);
    }
    return (84);
}
