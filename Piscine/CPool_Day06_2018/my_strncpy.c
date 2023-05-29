/*
** EPITECH PROJECT, 2018
** copy n caracter
** File description:
** Hello
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;
    
    while (src[index] != '\0' && index < n) {
        dest[index] = src[index];
        index++;
    }
    if (src[index] == '\0') {
        dest[index] = '\0';
    }
    return (dest);
}
