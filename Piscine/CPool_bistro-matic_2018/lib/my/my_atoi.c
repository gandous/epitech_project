/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** conv char * to int without error msg
*/

int my_strlen(char const *);

int check(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    else
        return 0;
}

int my_atoi(char const *str)
{
    int i;
    int nb = 0;
    int negatif_i = 0;
    int size = my_strlen(str);

    for (i = 0 ; i < size ; i++) {
        if (str[i] == '-')
            negatif_i++;
        if ((str[i + 1] < '0' || str[i + 1] > '9') && check(str[i]) == 1) {
            nb = nb * 10 + str[i] - '0';
            break;
        }
        if (check(str[i]) == 1)
            nb = nb * 10 + str[i] - '0';
    }
    if (negatif_i % 2 != 0)
        nb = -nb;
    return (nb);
}
