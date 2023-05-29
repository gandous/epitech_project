/*
** EPITECH PROJECT, 2018
** test programme
** File description:
** 
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    my_put_nbr(0);
    my_put_nbr(21);
    my_put_nbr(-21);
    my_put_nbr(2147483647);
    my_put_nbr(-2147483648);
    return (0);
}
