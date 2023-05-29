/*
** EPITECH PROJECT, 2019
** navy
** File description:
** header
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <sys/types.h>

static const int ERROR = 84;
static const int SUCCESS = 0;
static const int WIN = 42;
static const int FALSE = 0;
static const int TRUE = 1;

int navy(int argc, char **argv);

int error_gestion(int ac, char **av);
int is_navy_file(char *filepath);
int is_digit_navy(char c);
int is_char_alpha_navy(char c);

int connection(int ac, char **av, pid_t *pid_usr);
int sig_counter(int nbr);
int update_map(char **map, int x, int y);
int update_adv_map(char **map, int x, int y, int status);
int verif_win(char **map);

char **load_map(char *filepath);
int print_map(char **map);
int print_game(char **my_map, char **adv_map);
char *get_input(void);
int verif_input(char *input);
int place_boat(char **map, char *buffer);
char **generate_adv_map(void);

int play_advers_turn(pid_t pid_usr, char **map, char **adv_map);
int play_my_turn(pid_t pid_usr, char **map, char **adv_map);
int player_two_loop(pid_t pid_usr, char **map);
int player_one_loop(pid_t pid_usr, char **map);

int set_sigaction(void);
void receive_pos(int *x, int *y);
int share_pos(pid_t pid_usr, char *input, int *status);
int send_nbr(pid_t pid, int nbr);

int is_nbr_positif(char *str);
int mputchar(char c);
int mputstr(char *str);
int mputnbr(int nb);
int mgetnbr(char *str);

#endif /* NAVY_H_ */
