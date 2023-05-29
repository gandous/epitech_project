/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** none
*/
# include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char const *src)
{
    char *dest;
    int i;

    dest = malloc(sizeof(char*) * my_strlen(src));
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
