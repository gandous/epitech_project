/*
** EPITECH PROJECT, 2018
** mem alloc
** File description:
** alloc memory for the 2 string's arguments and return new zone's address
*/

#include <stdlib.h>

int my_strlen(char const *);

char *mem_alloc(char const *a, char const *b)
{
    char *result = NULL;
    int index = 0;

    result = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));
    if (result == NULL)
        exit(84);
    result[my_strlen(a) + my_strlen(b)] = '\0';
    if (my_strlen(a) > 0) {
        for (index = 0 ; a[index] != '\0'; index += 1)
            result[index] = a[index];
    }
    for (int i = 0 ; b[i] != '\0' ; i += 1) {
        result[index] = b[i];
        index += 1;
    }
    return (result);
}
