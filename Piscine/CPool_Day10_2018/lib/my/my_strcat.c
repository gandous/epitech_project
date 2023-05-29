/*
** EPITECH PROJECT, 2018
** str cat
** File description:
** str cat
*/

char *my_strcat(char *dest, char const *src)
{
    int index = 0;
    int index2 = 0;

    while (dest[index] != '\0') {
        index++;
    }
    while (src[index2] != '\0') {
        dest[index] = src[index2];
        index++;
        index2++;
    }
    dest[index] = '\0';
    return (dest);
}
