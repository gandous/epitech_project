/*
** EPITECH PROJECT, 2018
** main file
** File description:
** main file
*/

#include "../include/my.h"

int division(int nb1, int nb2)
{
    if (nb2 != 0) {
        my_put_nbr(nb1 / nb2);
    } else {
        my_putstr("Stop: division by zero\n");
        return (84);
    }
}

int modulo(int nb1, int nb2)
{
    if (nb2 != 0) {
        my_put_nbr(nb1 % nb2);
    } else {
        my_putstr("Stop: modulo by zero\n");
        return (84);
    }
}

int switch_sign(int nb1, int nb2, char signe)
{
    switch (signe) {
    case '+':
        my_put_nbr(nb1 + nb2);
        break;
    case '/':
        return (division(nb1, nb2));
        break;
    case '*':
        my_put_nbr(nb1 * nb2);
        break;
    case '-':
        my_put_nbr(nb1 - nb2);
        break;
    case '%':
        return (modulo(nb1, nb2));
        break;
    default:
        return (84);
        break;
    }
    return (0);
}

int check_size(int argc, char **argv)
{
    if (argc != 4) {
        return (1);
    }
    if (argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '-' &&
        argv[2][0] != '%' && argv[2][0] != '+') {
        return (1);
    }
    return (0);
}

int search_number(char *str)
{
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-') {
        return (0);
    } else {
        return (my_getnbr(str));
    }
}

int calcul(char **argv)
{
    int nb1 = search_number(argv[1]);
    int nb2 = search_number(argv[3]);
    char sign = argv[2][0];

    return (switch_sign(nb1, nb2, sign));
}

int main(int argc, char **argv)
{
    if (check_size(argc, argv) == 1) {
        return (84);
    }
    calcul(argv);
    return (0);
}
