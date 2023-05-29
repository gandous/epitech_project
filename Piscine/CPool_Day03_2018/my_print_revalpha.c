/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** 
*/

int my_print_revalpha(void)
{
    char letter = 'z';

    while (letter >= 'a') {
	my_putchar(letter);
	letter -= 1;
    }
    my_putchar('\n');
    return (0);
}

