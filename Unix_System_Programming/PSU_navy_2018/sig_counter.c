/*
** EPITECH PROJECT, 2019
** navy
** File description:
** counter the number of signal
*/

int sig_counter(int nbr)
{
    static int counter = 0;

    if (nbr == 0)
        counter = 0;
    if (nbr > 0)
        counter += nbr;
    return (counter);
}
