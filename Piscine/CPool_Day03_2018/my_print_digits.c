/*
** EPITECH PROJECT, 2018
** my_print_digits
** File description:
** 
*/

int my_print_digits(void)
{
    char letter = '0';

    while (letter <= '9') {
	my_putchar(letter);
	letter += 1;
    }
    my_putchar('\n');
    return (0);
}
