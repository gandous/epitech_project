/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** 
*/

int my_strlen (char const *str)
{
    int taille = 0;

    while (*str != '\0') {
        taille++;
        str += 1;
    }
    return (taille);
}
