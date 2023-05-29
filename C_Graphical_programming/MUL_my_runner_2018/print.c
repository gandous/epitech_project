/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** print
*/

#include <unistd.h>
#include "runner.h"
#include "create_const.h"
#include "game_loop.h"
#include "menu_h.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
