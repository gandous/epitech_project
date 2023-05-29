/*
** EPITECH PROJECT, 2018
** strcpy
** File description:
** copy a string to another
*/

char *my_strcpy(char *dest, char const *src)
{
    int index = 0;
    
    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return (&dest);
}
