/*
** EPITECH PROJECT, 2018
** result is nul 
** File description:
** return one if the char given in argument only constains zero
*/

int result_isnul(char *nbr, int size)
{
    int nb_zero = 0;

    for (int index = 0 ; nbr[index] != '\0' ; index += 1)
        if (nbr[index] == '0')
            nb_zero += 1;
    if (nb_zero == size)
        return (1);
    else
        return (0);
}
