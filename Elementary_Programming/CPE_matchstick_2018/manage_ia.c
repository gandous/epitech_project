/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** manage_ia
*/

#include <stdlib.h>
#include "matchstick.h"

int ia_remove(int stick_nb, char **map)
{
    int line = 1;

    while (stick_nb > sitck_on_line(map[line]) && map[line] != NULL)
        line += 1;
    if (map[line] == NULL) {
        line = 1;
        stick_nb = 1;
        while (stick_nb > sitck_on_line(map[line]) && map[line] != NULL)
            line += 1;
    }
    remove_stick(map[line], stick_nb);
    my_putstr("AI removed ");
    my_put_nbr(stick_nb);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    return (0);
}

int calc_to_remove(char **map, int max_stick)
{
    int stick_ream = count_reaming_stick(map);
    int stick_remove = 1;
    int fatal_nb = 1;

    for ( ; fatal_nb + max_stick + 1 < stick_ream ; fatal_nb += max_stick + 1);
    stick_remove = stick_ream - fatal_nb;
    if (stick_remove <= max_stick && stick_remove > 0)
        return (stick_remove);
    else
        return (1);
}

int ia_manager(char **map, int line, int max_stick)
{
    int stick_rm = calc_to_remove(map, max_stick);

    my_putstr("\nAI's turn...\n");
    ia_remove(stick_rm, map);
    return (0);
}