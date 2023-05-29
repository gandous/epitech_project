/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** return entry parameters
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(my_strlen(src) + 1);
    if (dest == NULL) {
        return (NULL);
    }
    for (int i = 0 ; src[i] != '\0' ; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
