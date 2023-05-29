/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (2 >= nb) {
        return (2);
    }
    for (int i = nb + 1; i < 2147483647 ; i++) {
        if (my_is_prime(i) == 1) {
            return (i);
            my_put_nbr(my_is_prime(i));
        }
        if (2147483647 == nb || nb < 0) {
            return (0);
        }

    }
    return (0);
}
