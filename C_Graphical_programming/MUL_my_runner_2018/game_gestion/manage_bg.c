/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** create_game_sprite
*/

#include <stdlib.h>
#include "runner.h"
#include "create_const.h"
#include "data_name.h"

void free_bg(sprite_anim_t **sprite)
{
    for (int i = 0 ; sprite[i] != NULL ; i += 1) {
        sfTexture_destroy(sprite[i]->texture);
        sfSprite_destroy(sprite[i]->sprite);
        free(sprite[i]);
    }
    free(sprite);
}

int check_bg(sprite_anim_t **my_bg, int index)
{
    if (my_bg[index] == NULL) {
        free_bg(my_bg);
        return (84);
    }
    return (0);
}

sprite_anim_t **create_bg(void)
{
    sprite_anim_t **my_bg = NULL;
    char *temp = NULL;
    sfVector2f pos;

    temp = malloc(sizeof(char) * 26);
    my_bg = malloc(sizeof(sprite_anim_t *) * 14);
    if (temp == NULL || my_bg == NULL)
        return (NULL);
    temp[25] = '\0';
    my_strcpy(IMG_BG, temp);
    for (int i = 14, index = 0; i / 2 > 0 ; i -= 1, index += 1) {
        temp[BG_TO_REPLACE] = '0' + i / 2;
        pos = create_vec((index % 2) * WINDOW_W, 0);
        my_bg[index] = create_anim_s(temp, pos, 1);
        my_bg[index]->vect  = create_vec(((8 - i / 2) - 1) * -0.3, 0);
        if (check_bg(my_bg, index) == 84)
            return (NULL);
    }
    my_bg[13] = NULL;
    return (my_bg);
}

void display_bg(sprite_anim_t **all_bg, sfRenderWindow *win)
{
    sprite_anim_t *bg = NULL;
    sfVector2f pos;

    for (int i = 0 ; all_bg[i] != NULL ; i += 1) {
        bg = all_bg[i];
        sfSprite_move(bg->sprite, bg->vect);
        pos = sfSprite_getPosition(bg->sprite);
        if (pos.x <= -WINDOW_W + 5)
            sfSprite_setPosition(bg->sprite, create_vec(WINDOW_W, 0));
        sfRenderWindow_drawSprite(win, bg->sprite, NULL);
    }
}
