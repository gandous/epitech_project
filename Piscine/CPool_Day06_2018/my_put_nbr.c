/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** 
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    long taille = nb;
    long puissance = 1;
    int nb0 = 0;
    long nblong = nb;

    if (nblong < 0){
        nblong = nblong * -1;
        my_putchar('-');
    }
    if (nblong == 0){
        my_putchar('0');
    } else {
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
        while (puissance > 0) {
            my_putchar(nblong / puissance + 48);
            nblong %=  puissance;
            puissance /= 10;
        }
        while (nb0 >= 1) {
            if (nb0 >= 1) {
                my_putchar('0');
                nb0--;
            }
        }
    }
    my_putchar('\n');
    return (0);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
    return (0);
}
