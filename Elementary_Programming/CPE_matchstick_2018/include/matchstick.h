/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

int matchstick(int argc, char **argv);
char **generate_table(int size);
void my_putstr(char *str);
void display_map(char **map);
void delete_map(char **map);
void my_putchar(char c);
int player_manager(char **map, int size, int max_stick);
int my_getnbr(char *str);
int is_number(char *str);
void my_put_nbr(int nb);
int verif_sitck(char *line, int stick);
void remove_stick(char *line, int stick);
int count_reaming_stick(char **map);
int ia_manager(char **map, int size, int max_stick);
int sitck_on_line(char *line);

#endif
