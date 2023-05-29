/*
** EPITECH PROJECT, 2018
** my hunter | header
** File description:
** my hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 960
#define DUCK_S 3
#define DUCK_W 37
#define DUCK_H 32
#define DUCK_NB 2
#define DUCK_TW DUCK_W * DUCK_S
#define CROSS_S 0.4
#define CROSS_W 128.0 * CROSS_S / 2
#define CROSS_H 128.0 * CROSS_S / 2
#define DOG_S 3
#define DOG_W 56
#define DOG_H 43
#define IMG_DUCK "resource/duck_bleu.png"
#define IMG_BALL "resource/ball.png"
#define IMG_CROSSHAIR "resource/crosshair.png"
#define IMG_DOG_SEARCH "resource/dog_search.png"
#define IMG_DOG_FIND "resource/dog_find.png"
#define IMG_DOG_JUMP "resource/dog_jump.png"
#define FONT_PATH "resource/PressStart2P.ttf"
#define S_GUN "resource/gunshot.wav"
#define S_MUSIC "resource/music.ogg"
#define S_SHELL "resource/shell_fall.wav"
#define S_DUCK "resource/duck_sound.wav"

typedef struct sprite_anim {
    sfSprite *sprite;
    float dest_x;
    float dest_y;
    sfVector2f speed;
    sfIntRect rect;
    sfTexture *texture;
    int dead;
} sprite_anim_t;

typedef struct sprite_stat {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_stat_t;

typedef struct text {
    sfText *text;
    sfFont *font;
} text_t;

typedef struct sound {
    sfSound *sound;
    sfSoundBuffer *buff;
} sound_t;

typedef struct my_sprite {
    int duck_reaming;
    int duck_alive;
    sprite_anim_t **my_duck;
    int shot;
    sprite_stat_t **ball;
    text_t *text;
    int score;
    char *score_c;
    sound_t *s_gunshot;
    sound_t *s_duck;
    sound_t *s_shell;
    sfMusic *s_music;
    sprite_stat_t *background;
    sprite_stat_t *foreground;
    sprite_stat_t *crosshair;
    sfClock *clock;
} my_sprite_t;

void move_rect(sfIntRect *rect, int offset, int max_value);
sfSprite *create_sprite(char *image, int scale);
sfRenderWindow *create_window(char *name, int width, int height);
sfIntRect create_rect(int x, int y, int width, int height);
sfVector2f create_vector(float x, float y);
float time_tosecond(sfClock *clock);
sprite_anim_t **create_duck_sprite(int nombre);
void display_duck(my_sprite_t *all_sprite, sfRenderWindow *window);
void delete_duck(my_sprite_t *all_sprite);
void anim_duck(my_sprite_t *all_sprite);
int alea(int min, int max);
sfVector2f create_scale(float direction, float scale);
my_sprite_t *create_all_sprite(void);
int duck_is_touch(sfMouseButtonEvent mouse, sprite_anim_t *my_duck);
sfSprite *inside_the_screen(sfSprite *my_sprite);
void to_dead_sprite(sprite_anim_t *my_duck);
int duck_is_nul(sfSprite *sprite);
sfVector2f create_speed(float x, float y, sfVector2f dep);
sprite_anim_t *change_dir(sprite_anim_t *my_sprite);
sprite_anim_t **regenerate_sprite(sprite_anim_t **sprite);
sprite_stat_t **create_ball(void);
void delete_ball(sprite_stat_t **all_sprite);
void display_ball(sfRenderWindow *win, sprite_stat_t **all, int shot);
text_t *create_text(void);
void display_text(sfRenderWindow *window, text_t *txt);
void delete_text(text_t *temp);
char *create_score(void);
void int_to_string(int score, char *temp);
sound_t *load_sound(char *filepath);
void delete_sound(sound_t *sound);
void close_window(sfRenderWindow *window);
void manage_mouse_click(sfMouseButtonEvent mouse, my_sprite_t *all_sprite);
void analyse_event(sfRenderWindow *window, sfEvent event, my_sprite_t *sprite);
void game(void);
void delete_stat_sprite(sprite_stat_t *sprite);
void regenerate_all(my_sprite_t *sprite);
void play_duck(my_sprite_t *sprite);
void play_music(sfMusic *music);
sprite_stat_t *create_stat_sprite(char *filepath, float scale);
void delete_stat_sprite(sprite_stat_t *sprite);
sprite_anim_t *create_anim(char *filepath, float scale);
void delete_anim(sprite_anim_t *temp);
void anim_intro(sfRenderWindow *window, my_sprite_t *sprite);
sfVector2f change_speed(sfVector2f speed);

#endif