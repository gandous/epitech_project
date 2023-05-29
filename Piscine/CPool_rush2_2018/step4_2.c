/*
** EPITECH PROJECT, 2018
** step 4 part 2
** File description:
** step 4 part 2
*/

int langage(char *text, int lang[27])
{
    int index = 0;
    int correspondance = 0;
    int temp;

    while (text[index] != '\0') {
        if (text[index] >= 'a' && text[index] <= 'z') {
            temp = text[index] - 'a';
            correspondance += lang[temp];
            lang[temp] = 0;
        }
        index++;
    }
    return (correspondance);
}

void to_lower(char *text)
{
    for (int i = 0 ; text[i] != '\0' ; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + 32;
        }
    }
}

char *find_language(int en, int fr, int gr, int sp)
{
    if (en > fr && en > gr && en > sp) {
        return ("English");
    }
    if (fr > en && fr > gr && fr > sp) {
        return ("French");
    }
    if (gr > en && gr > fr && gr > sp) {
        return ("German");
    }
    if (sp > en && sp > fr && sp > gr) {
        return ("Spanish");
    }
}

int text_size(char *text)
{
    int size = 0;
    int index = 0;

    while (text[index] != '\0') {
        if (text[index] >= 'a' && text[index] <= 'z') {
            size++;
        }
        if (text[index] >= 'A' && text[index] <= 'Z') {
            size++;
        }
        index++;
    }
    return (size);
}

int search_letter(char *text, char letter)
{
    int index = 0;
    int nb_letter = 0;
    char letter2;

    while (text[index] != '\0') {
        if (text[index] == letter || text[index] == letter2) {
            nb_letter += 1;
        }
        index += 1;
    }
    return (nb_letter);
}
