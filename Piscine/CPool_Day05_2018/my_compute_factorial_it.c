/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** 
*/

int my_compute_factorial_it(int nb)
{
    int number = 1;
    
    if (nb == 0) {
        return (1);
    }
    if (nb == 1) {
        return (1);
    }
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    while (nb > 0) {
        number *= nb;
        nb--;
    }
    return (number);
}
