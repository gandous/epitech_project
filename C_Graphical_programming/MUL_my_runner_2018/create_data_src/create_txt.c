/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** create_txt
*/

#include <stdlib.h>
#include "game_loop.h"
#include "data_name.h"
#include "create_const.h"

text_data_t *create_text(sfVector2f pos, char *font, char *str, sfColor color)
{
    text_data_t *temp = NULL;

    temp = malloc(sizeof(text_data_t));
    if (temp == NULL)
        return (NULL);
    temp->font = sfFont_createFromFile(font);
    temp->text = sfText_create();
    sfText_setFont(temp->text, temp->font);
    sfText_setString(temp->text, str);
    sfText_setPosition(temp->text, pos);
    sfText_setColor(temp->text, color);
    return (temp);
}

void free_text(text_data_t *temp)
{
    sfText_destroy(temp->text);
    sfFont_destroy(temp->font);
    free(temp);
}