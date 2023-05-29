/*
** EPITECH PROJECT, 2018
** remove zero
** File description:
** remove the 0 before the number
*/

#include <stdlib.h>

char *remove_zero(char *str, int nb_signe)
{
    char *output = NULL;
    int size = 0;
    int index = 0;
    int neg = 0;

    for (index = 0 ; str[index] == '0' ; index += 1);
    for (int i = index ; str[i] != '\0' ; i += 1)
        size += 1;
    if (nb_signe == 1)
        size += 1;
    output = malloc(sizeof(char) * (size + 1));
    if (nb_signe == 1) {
        output[0] = '-';
        neg = 1;
    }
    for (int i = index; str[i] != '\0' ; i += 1) {
        output[i - index + neg] = str[i];
    }
    output[size] = '\0';
    free(str);
    return (output);
}
