/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** create_const
*/

#ifndef CREATE_CONST_H_
#define CREATE_CONST_H_

#include <SFML/Graphics.h>

sfVector2f create_vec(float x, float y);
sfIntRect create_rect(int x, int y, int width, int height);
sprite_anim_t *create_anim_s(const char *filepath, sfVector2f pos, float scale);
int my_strlen(const char *str);
void my_strcpy(const char *src, char *dest);
void move_rect(sfIntRect *rect, int offset, int max_value);
float time_tosecond(sfClock *clock);
sfColor create_color(int r, int g, int b, int a);
sprite_static_t *create_static_s(const char *file, sfVector2f pos, float s);
void free_static_s(sprite_static_t *sprite);
text_data_t *create_text(sfVector2f pos, char *font, char *str, sfColor color);
void free_text(text_data_t *temp);

#endif