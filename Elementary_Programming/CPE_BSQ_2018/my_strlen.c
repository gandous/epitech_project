/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** count string size
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int taille = 0;

    if (str == NULL) {
        return (0);
    }
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        taille++;
    }
    return (taille);
}
