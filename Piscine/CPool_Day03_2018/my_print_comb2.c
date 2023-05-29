/*
** EPITECH PROJECT, 2018
** my_print_comb2 
** File description:
** 
*/

void display(int nb1, int nb2, int nb3, int nb4)
{
    my_putchar(nb1+48);
    my_putchar(nb2+48);
    my_putchar(' ');
    my_putchar(nb3+48);
    my_putchar(nb4+48);
    if ((nb1 == 9) && (nb2 == 8) && (nb3 == 9) && (nb4 == 9)) {
    } else {
        my_putchar(',');
        my_putchar(' ');
    }
}

void part1(int nombre1, int nombre2, int nombre3, int nombre4)
{
    while (nombre3 <= 9) {
        while (nombre4 <= 9) {
            display(nombre1, nombre2, nombre3, nombre4);
            nombre4++;
        }
        nombre3++;
        nombre4 = 0;
    }
}
    
int my_print_comb2(void)
{
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;
    int number4 = 1;

    while (number1 <= 9) {
        while (number2 <= 9) {
            part1(number1, number2, number3, number4);
            number2++;
            number3 = number1;
            number4 = number2+1;
        }
        number1++;
        number2 = 0;
        number3 = number1;
        number4 = number2+1;
    }
    my_putchar('\n');
    return (0);
}
