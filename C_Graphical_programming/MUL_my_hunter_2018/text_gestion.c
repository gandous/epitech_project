/*
** EPITECH PROJECT, 2018
** text gestion
** File description:
** all function for text
*/

#include "my_hunter.h"

text_t *create_text(void)
{
    text_t *temp;
    sfColor txt_color = {237, 237, 237, 255};

    temp = malloc(sizeof(text_t));
    if (temp == NULL)
        return (NULL);
    temp->font = sfFont_createFromFile(FONT_PATH);
    temp->text = sfText_create();
    sfText_setFont(temp->text, temp->font);
    sfText_setString(temp->text, "000000");
    sfText_setPosition(temp->text, create_vector(767, 832));
    sfText_setColor(temp->text, txt_color);
    return (temp);
}

void display_text(sfRenderWindow *window, text_t *txt)
{
    sfRenderWindow_drawText(window, txt->text, NULL);
}

void delete_text(text_t *temp)
{
    sfText_destroy(temp->text);
    sfFont_destroy(temp->font);
    free(temp);
}

char *create_score(void)
{
    char *temp = NULL;

    temp = malloc(sizeof(char) * 7);
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; i < 6 ; i += 1) {
        temp[i] = '0';
    }
    temp[6] = '\0';
    return (temp);
}

void int_to_string(int score, char *temp)
{
    int index = 5;

    if (score > 999999) {
        temp = "TO BIG";
        return;
    }
    while (score >= 1) {
        temp[index] = score % 10 + '0';
        index -= 1;
        score /= 10;
    }
    while (index >= 0) {
        temp[index] = '0';
        index -= 1;
    }
}