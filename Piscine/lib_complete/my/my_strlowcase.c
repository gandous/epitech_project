/*
** EPITECH PROJECT, 2018
** str low case
** File description:
** str low case
*/

char *my_strlowcase(char *str)
{
    for (int i = 0 ; str[i] != '\0') {
        if (str[i] > 'A' && str[i] < 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return (str);

}
