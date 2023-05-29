/*
** EPITECH PROJECT, 2018
** step2.c
** File description:
** step2.c
*/

#include "include/my.h"

int search_letter(char *text, char letter)
{
    int index = 0;
    int nb_letter = 0;
    char letter2;

    if (letter >= 65 && letter <= 90) {
        letter2 = letter + 32;
    } else {
        letter2 = letter - 32;
    }
    while (text[index] != '\0') {
        if (text[index] == letter || text[index] == letter2) {
            nb_letter += 1;
        }
        index += 1;
    }
    return (nb_letter);
}

int more_letter(int argc, char **argv)
{
    int index2 = 2;

    while (index2 < argc) {
        my_putchar(argv[index2][0]);
        my_putchar(':');
        my_put_nbr(search_letter(argv[1], argv[index2][0]));
        index2 += 1;
    }
    return (0);
}

/*int main(int argc, char **argv)
{
    more_letter(argc, argv);
    }*/

