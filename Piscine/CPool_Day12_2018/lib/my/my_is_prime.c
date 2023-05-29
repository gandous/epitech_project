/*
** EPITECH PROJECT, 2018
** prime number
** File description:
** calcule if the number is prime or not
*/

int my_is_prime(int nb)
{
    int number = nb-1;
    if (nb < 0) {
        return (0);
    }
    while (number > 1) {
        if ((nb % number) == 0) {
            return (0);
        }
        number--;
    }
    return (1);
}
