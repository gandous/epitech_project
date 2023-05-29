/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** start_menu_event
*/

#include "runner.h"
#include "create_const.h"
#include "menu_h.h"

int button_start_touch(sfVector2f pos_m, start_menu_t *menu_data)
{
    sfVector2f pos_r = sfSprite_getPosition(menu_data->button_p->sprite);
    sfVector2f pos_q = sfSprite_getPosition(menu_data->button_q->sprite);

    if (pos_m.x >= pos_r.x && pos_m.x <= pos_r.x + BUTTON_W) {
        if (pos_m.y >= pos_r.y && pos_m.y <= pos_r.y + BUTTON_H)
            return (0);
        else if (pos_m.y >= pos_q.y && pos_m.y <= pos_q.y + BUTTON_H)
            return (2);
        else
            return (3);
    } else
        return (3);
}

int start_mouse_click(sfMouseButtonEvent mouse, start_menu_t *menu_data)
{
    if (mouse.button == 0)
        return (button_start_touch(create_vec(mouse.x, mouse.y), menu_data));
    else
        return (3);
}

int start_menu_event(sfRenderWindow *win, sfEvent event, start_menu_t *menu_d)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        switch (event.type) {
        case sfEvtClosed :
            return (2);
        case sfEvtKeyPressed:
            return (menu_key_pressed(event.key));
        case sfEvtMouseButtonPressed:
            return (start_mouse_click(event.mouseButton, menu_d));
        default:
            return (3);
        }
    }
    return (3);
}
