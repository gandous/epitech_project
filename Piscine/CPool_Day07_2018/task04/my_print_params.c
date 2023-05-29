/*
** EPITECH PROJECT, 2018
** my print params
** File description:
** print the arguments
*/

int main(int argc, char **argv)
{
    for (int i = 0 ; i < argc ; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
