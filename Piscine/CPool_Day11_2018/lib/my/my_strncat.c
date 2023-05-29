/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int index = 0;
    int index2 = 0;

    for (index = 0 ; dest[index] != '\0' ; index++);
    while (src[index2] != '\0' && index2 < nb) {
        dest[index] = src[index2];
        index2++;
        index++;
    }
    if (src[index2] == '\0') {
        dest[index] = '\0';
    }
    return (dest);
}
