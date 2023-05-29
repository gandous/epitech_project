/*
** EPITECH PROJECT, 2018
** match
** File description:
** check if 2 string match
*/

int skip_stars(char const *s1, int index, char next_char)
{
    while (s1[index] != next_char && s1[index] != '\0') {
        index++;
    }
    return (index);
}

int match(char const *s1, char const *s2)
{
    int index = 0;
    int index2 = 0;

    while (s1[index] != '\0' && s2[index2] != '\0') {
        if (s2[index2] == '*') {
            index2 += 1;
            index = skip_stars(s1, index, s2[index2]);
        } else {
            index += 1;
            index2 += 1;
        }
        if (s1[index] != s2[index2] && s2[index2] != '*') {
            return (0);
        }

    }
    return (1);
}
