/*
** EPITECH PROJECT, 2018
** sort param
** File description:
** sort param
*/

void print_word(char start_char, char *text)
{
    if (start_char == text[0]) {
        my_putstr(text);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    for (char i = 0 ; i < 127 ; i++) {
        for (int index = 0 ; index < argc ; index++) {
            print_word(i, argv[index]);
        }
    }
    return (0);
}
