/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** 
*/

int my_print_alpha(void)
{
    char letter = 'a';

    while (letter <= 'z') {
	my_putchar(letter);
	letter += 1;
    }
    my_putchar('\n');
    return (0);
}
