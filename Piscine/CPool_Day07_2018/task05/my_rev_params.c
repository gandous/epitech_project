/*
** EPITECH PROJECT, 2018
** my rev param
** File description:
** print the param in the other sens
*/

int main(int argc, char **argv)
{
    for (int i = argc-1 ; i >= 0 ; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
