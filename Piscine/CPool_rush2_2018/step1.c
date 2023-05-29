/*
** EPITECH PROJECT, 2018
** what language is this?
** File description:
** what language is this
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
        index  += 1;
    }
    return (nb_letter);
}

int main(int argc, char **argv)
{
    my_putchar(argv[2][0]);
    my_putchar(':');
    my_put_nbr(search_letter(argv[1], argv[2][0]));
    return (0);
}
