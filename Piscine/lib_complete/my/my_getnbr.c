/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** take the number
*/

int recup_number(char const *str, int puissance, long nb)
{
    int number = 0;

    while ((*str >= '0') && (*str <= '9' )) {
        nb = nb + ((*str - 48) * puissance);
        puissance *= 10;
        str--;
    }
    if (*str == '-') {
        nb = nb * -1;
    }
    if ((nb > 2147483647) || (nb < -2147483648)) {
        number = 0;
    } else {
        number = nb;
    }
    return (number);
}

int my_getnbr(char const *str)
{
    int taille = 0;
    long nb = 0;
    long puissance = 1;
    int number = 0;

    while ((*str < '0' || *str > '9') && (*str != '\0')) {
        str++;
    }
    if (*str != '\0') {
        while ((*str >= '0') && (*str <= '9' )) {
            taille++;
            str++;
        }
    }
    if (taille > 0) {
        str--;
        number = recup_number(str, puissance, nb);
    }
    return (number);
}
