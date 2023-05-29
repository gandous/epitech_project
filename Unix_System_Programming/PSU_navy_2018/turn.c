/*
** EPITECH PROJECT, 2019
** navy
** File description:
** player turns
*/

#include <stdlib.h>
#include "navy.h"

char *get_usr_input(void)
{
    char *input = get_input();

    while (input != NULL && verif_input(input) == ERROR) {
        free(input);
        input = get_input();
    }
    if (input != NULL)
        input[2] = '\0';
    return (input);
}

int play_my_turn(pid_t pid_usr, char **map, char **adv_map)
{
    char *input = get_usr_input();
    int status = 0;

    if (input == NULL)
        return (ERROR);
    if (share_pos(pid_usr, input, &status) == ERROR)
        return (ERROR);
    if (status == 2) {
        mputstr(input);
        mputstr(": hit\n\n");
    } else if (status == 3)
        return (WIN);
    else {
        mputstr(input);
        mputstr(": miss\n\n");
    }
    update_adv_map(adv_map, input[0] - 'A', input[1] - '0', status);
    free(input);
    return (0);
}

static void put_play_advers_turn(int x, int y, int mode)
{
    mputchar(x + 'A' - 1);
    mputchar(y + '0');
    if (mode == 1)
        mputstr(": hit\n\n");
    if (mode == 2)
        mputstr(": miss\n\n");
}

int play_advers_turn(pid_t pid_usr, char **map, char **adv_map)
{
    int x = 0;
    int y = 0;

    mputstr("waiting for enemy’s attack...\n");
    receive_pos(&x, &y);
    if (update_map(map, x, y) == 0) {
        if (verif_win(map) == WIN) {
            send_nbr(pid_usr, 3);
            return (WIN);
        } else {
            send_nbr(pid_usr, 2);
            put_play_advers_turn(x, y, 1);
        }
    } else {
        send_nbr(pid_usr, 4);
        put_play_advers_turn(x, y, 2);
    }
    return (0);
}
