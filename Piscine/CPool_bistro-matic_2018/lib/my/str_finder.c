/*
** EPITECH PROJECT, 2018
** my_strfinder
** File description:
** return 1 if tho str are eguals
*/

int my_strlen(char *);

int str_finder(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0 ; str1[i] && str2[i] ; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
