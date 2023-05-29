/*
** EPITECH PROJECT, 2018
** is sup 
** File description:
** check if number 1 > nb 2
*/

int str_len(char *);

int char_issup(char *nb1, char *nb2)
{
    int size1 = str_len(nb1);
    int size2 = str_len(nb2);
    int index = 0;

    if (size1 > size2) {
        return (1);
    } else if (size1 < size2) {
        return (0);
    }
    for (index = 0 ; nb1[index] == nb2[index] && nb1[index] != '\0' ;
         index += 1);
    if (nb1[0] == '\0')
        return (0);
    if (nb1[index] > nb2[index]) {
        return (1);
    } else if (nb1[index] < nb2[index]) {
        return (0);
    }
    return (1);
}
