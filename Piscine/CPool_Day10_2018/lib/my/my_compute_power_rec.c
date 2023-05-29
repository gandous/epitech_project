/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** calcule number one at power of number 2
*/

int my_compute_power_rec(int nb, int p)
{
    long number = nb;
    int nb_return;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (p == 1) {
        return (nb);
    }
    number = nb * my_compute_power_rec(nb, p-1);
    if (number > 2147483647 || number < -2147483648) {
        return (0);
    }
    nb_return = number;
    return (nb_return);
}
