/*
** EPITECH PROJECT, 2018
** reverse a string
** File description:
** task
*/

char *my_revstr(char *str)
{
    int taille = 0;
    int first = 0;
    int save;

    while (str[taille] != '\0') {
        taille++;
    }
    taille -= 1;
    while (taille >= first) {
        save = str[first];
        str[first] = str[taille];
        str[taille] = save;
        taille--;
        first++;
    }
    return (str);
}
