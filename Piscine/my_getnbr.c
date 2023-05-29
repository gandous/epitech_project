/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** 
*/

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
    }
    return (number);
}

int main()
{
    char texte[7] = "admkaa";
    int aa = my_getnbr(&texte);
    my_put_nbr(aa);
    char texte2[7] = "bh2bbb";
    int bb = my_getnbr(&texte2);
    my_put_nbr(bb);
}
