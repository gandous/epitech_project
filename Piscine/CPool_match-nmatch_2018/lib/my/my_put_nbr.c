/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** print a number
*/

void my_putchar(char c);

void display_zero(int nb0)
{
    while (nb0 >= 1) {
        if (nb0 >= 1) {
            my_putchar('0');
            nb0--;
        }
    }

}

long nb_isneg(long nb)
{
    if (nb < 0){
	nb = nb * -1;
	my_putchar('-');
    }
    return (nb);
}

int number_null(long nb)
{
    if (nb == 0) {
        my_putchar('0');
        return (1);
    }
    return (0);
}

void display_number(long puissance, long nblong)
{
    while (puissance > 0) {
        my_putchar(nblong / puissance + 48);
        nblong %=  puissance;
        puissance /= 10;
    }
}

int my_put_nbr(int nb)
{
    long taille = nb;
    long puissance = 1;
    int nb0 = 0;
    long nblong = nb_isneg(nb);

    if (number_null(nblong) == 1)
        return (0);
    while ((nblong % 10) == 0) {
        nb0++;
        nblong /= 10;
    }
    taille = nblong;
    while (taille >= 1) {
        taille = taille / 10;
        puissance = puissance * 10;
    }
    puissance /= 10;
    display_number(puissance, nblong);
    return (0);
}
