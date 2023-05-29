/*
** EPITECH PROJECT, 2018
** step3.c
** File description:
** step3.c
*/

#include "include/my.h"

int display_pour(int nb_lettre, int size)
{
    int temp = nb_lettre * 10000;

    temp = temp / size;
    my_putchar('(');
    my_put_nbr(temp / 100);
    my_putchar('.');
    if ((temp % 100) < 10) {
        my_putchar('0');
    }
    my_put_nbr(temp % 100);
    my_putchar('%');
    my_putchar(')');
    return (temp);
}

int text_size(char *text)
{
    int size = 0;
    int index = 0;

    while (text[index] != '\0') {
        if (text[index] >= 'a' && text[index] <= 'z') {
            size++;
        }
        if (text[index] > 'A' && text[index] <= 'Z') {
            size++;
        }
        index++;
    }
    return (size);
}

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
    int size = text_size(argv[1]);
    int nb_letter;
    int my_pourcent = 0;

    while (index2 < argc) {
        nb_letter = search_letter(argv[1], argv[index2][0]);
        my_putchar(argv[index2][0]);
        my_putchar(':');
        my_put_nbr(nb_letter);
        my_putchar(' ');
        display_pour(nb_letter, size);
        my_putchar('\n');
        index2 += 1;
    }
    return (0);
}

int main(int argc, char **argv)
{
    more_letter(argc, argv);
}

