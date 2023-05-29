/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** game_loop
*/

#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include "runner.h"

typedef struct sprite_list_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vect;
    int is_spike;
    struct sprite_list_s *next;
} sprite_list_t;

typedef struct game_data_s {
    sprite_anim_t **background;
    sprite_anim_t *perso;
    float perso_y;
    sfClock *jump_clock;
    int perso_jump;
    sfClock *clock;
    sprite_list_t *list;
    float game_speed;
    map_data_t *map;
    int loop;
    sfBool quit;
    int index_perso;
    sprite_static_t *bg_text;
    text_data_t *text_score;
    int score;
    char *score_str;
    sfClock *clock_score;
    sfMusic *jump_sound;
    sfMusic *death_sound;
} game_data_t;

int runner_loop(sfRenderWindow *window, map_data_t *data_map, int loop);
void game_event(sfBool *q, sfEvent event, sfRenderWindow *w, game_data_t *d);
sprite_anim_t **create_bg(void);
void display_bg(sprite_anim_t **all_bg, sfRenderWindow *win);
sprite_anim_t *create_perso(map_data_t *map_data);
void anim_perso(sprite_anim_t *perso, int perso_jump);
game_data_t *create_all_sprite(map_data_t *map_data);
void display_sprite(game_data_t *sprite, sfRenderWindow *win);
void anim_sprite(game_data_t *sprite);
void free_anim_s(sprite_anim_t *sprite);
void free_game_data(game_data_t *all_sprite);
void free_bg(sprite_anim_t **sprite);
sprite_list_t *create_map_list(map_data_t *map);
void display_map(sprite_list_t **my_list, sfRenderWindow *win, game_data_t *d);
void free_list(sprite_list_t *list);
sprite_list_t *create_line(map_data_t *map_data, sprite_list_t *list, int x);
void update_map(sprite_list_t **list, sprite_list_t *previous, game_data_t *d);
void perso_jump(game_data_t *game_data);
int player_touch_ground(game_data_t *game_data);
void verif_pos_perso(game_data_t *game_data);
int detect_wall(game_data_t *game_data);
text_data_t *create_score_txt(char *str);
void update_score(sfRenderWindow *win, game_data_t *game_data);
sfTexture *get_texture(char **map, int x, int y, int height);
void calc_jump(game_data_t *game_data, double spd, double angle, float speed);
void change_texture(sprite_anim_t *perso, const char* img, float w, float h);

#endif