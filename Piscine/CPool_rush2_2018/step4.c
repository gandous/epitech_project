/*
** EPITECH PROJECT, 2018
** step3.c
** File description:
** step3.c
*/

#include "include/my.h"
#include "include/rush.h"
#include <unistd.h>

int check_arguments(char **argv, int argc)
{
    for (int i = 2 ; i < argc ; i++) {
        if (my_strlen(argv[i]) > 1) {
            return (1);
        }
        if (argv[i][0] < 'A' || (argv[i][0] > 'Z' && argv[i][0] < 'a')
            || argv[i][0] > 'z') {
            return (1);
        }

    }
    return (0);
}

char *search_language(char *text)
{
    int english[27] = {816, 149, 278, 425, 1270, 222, 201, 609, 696, 15, 077,
                       402, 240, 674, 750, 192, 9, 598, 632, 905, 275, 97,
                       236, 15, 197, 7};
    int french[27] = {763, 90, 326, 366, 1471, 106, 86 , 73, 752, 61, 7, 545,
                      296, 709, 579, 252, 136, 669, 794, 724, 631, 183, 4, 42,
                      12, 32};
    int german[27] = {651, 188, 273, 507, 1639, 165, 300, 457, 655, 26, 141,
                      343, 253, 977, 259, 67, 1, 700, 727, 615, 416, 84, 192,
                      3, 3, 113};
    int spanish[27] = {1152, 221, 401, 501, 1218, 69, 176, 70, 624, 49, 1,
                       496, 315, 671, 868, 251, 87, 687, 797, 463, 292,
                       113, 1, 21, 100, 46};
    int en = langage(text, english);
    int fr = langage(text, french);
    int gr = langage(text, german);
    int sp = langage(text, spanish);

    my_putstr("=>");
    my_putstr(find_language(en, fr, gr, sp));
    my_putchar('\n');
    return (find_language(en, fr, gr, sp));
}

void display_pour(int nb_lettre, int size)
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
}

int more_letter(int argc, char **argv)
{
    int index2 = 2;
    int size = text_size(argv[1]);
    int nb_letter;

    to_lower(argv[1]);
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

/*int main(int argc, char **argv)
{
    if (argc >= 3) {
        if (check_arguments(argv, argc) == 1) {
            write(2, "Erreur : argument invalid\n", 28);
            return (84);
        } else {
            more_letter(argc, argv);
            search_language(argv[1]);
            return (0);
        }
    } else {
        write(2, "Erreur : not enough arguments\n", 31);
        return (84);
    }
    }*/

