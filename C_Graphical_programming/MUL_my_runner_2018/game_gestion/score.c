/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** score
*/

#include "game_loop.h"
#include "create_const.h"
#include "data_name.h"
#include "runner.h"

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

text_data_t *create_score_txt(char *str)
{
    sfVector2f pos = create_vec(WINDOW_W - 300, 40);
    sfColor col = create_color(0, 0, 0, 255);
    text_data_t *text = create_text(pos, FONT, str, col);

    return (text);
}

void update_score(sfRenderWindow *win, game_data_t *game_data)
{
    if (time_tosecond(game_data->clock_score) > 1.0) {
        game_data->score += 1;
        int_to_string(game_data->score, game_data->score_str);
        sfText_setString(game_data->text_score->text, game_data->score_str);
        sfClock_restart(game_data->clock_score);
    }
    sfRenderWindow_drawSprite(win, game_data->bg_text->sprite, NULL);
    sfRenderWindow_drawText(win, game_data->text_score->text, NULL);
}