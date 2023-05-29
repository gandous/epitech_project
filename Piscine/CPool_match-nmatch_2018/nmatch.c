/*
** EPITECH PROJECT, 2018
** nmatch
** File description:
** count the number of match betwen to text
*/

int match(char const *s1, char const *s2);

int count_asterisk(char const *s2)
{
    int nb = 0;
    int index = 0;

    while (s2[index] != '\0') {
        if (s2[index] == '*') {
            nb++;
        }
        index++;
    }
    return (nb);
}

int jump_asterisk(char const *s2)
{
    int index = 0;

    while (s2[index] == '*') {
        index++;
    }
    return (index);
}

int check_match

int nmatch(char const *s1, char const *s2)
{
    int index = 0;
    int index2 = jump_asterisk(s2);
    int nb_match = 0;

    if (count_asterisk(s2) < 2)
        return (0);
    while (s1[index] != '\0') {
        if (s1[index] == s2[index2]) {
            my_putchar('m');
        }
        my_putchar(s1[index]);
        index++;
    }
}

int main(){
    nmatch("abcbd", "*b*");
}
