/*
** EPITECH PROJECT, 2018
** my_print_comb
** File description:
** 
*/

int my_print_comb(void)
{
    int number1 = 0;
    int number2 = 1;
    int number3 = 2;

    while (number1 <= 7) {
	while (number2 <= 8) {
	    while (number3 <=9) {
		my_putchar(number1+48);
		my_putchar(number2+48);
		my_putchar(number3+48);
		if (number1 != 7){
		    my_putchar(',');
                    my_putchar(' ');
		}
		number3 += 1;
	    }
	    number2 += 1;
	    number3 = number2 + 1;
	}
	number1 += 1;
	number2 = number1 + 1;
	number3 = number2 + 1;
    }
    my_putchar('\n');
    return (0);
}
