/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** 
*/

int my_compute_power_it(int nb, int p)
{
    int count = 1;
    long number = nb;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    while (count < p && number < 2147483647) {
        number *= nb;
        count++;
    }
    if (number > 2147483647) {
        return (0);
    }
    return (number);
}
