/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Share x y position
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "navy.h"

int send_nbr(pid_t pid, int nbr)
{
    for (int i = 0 ; i < nbr ; i++) {
        if (kill(pid, SIGUSR1) == -1)
            return (ERROR);
        usleep(20000);
    }
    if (kill(pid, SIGUSR2) == -1)
        return (ERROR);
    usleep(20000);
    return (SUCCESS);
}

int share_pos(pid_t pid_usr, char *input, int *status)
{
    int x = input[0] - 'A';
    int y = input[1] - '0';

    sig_counter(0);
    if (send_nbr(pid_usr, x + 1) == ERROR)
        return (ERROR);
    if (send_nbr(pid_usr, y) == ERROR)
        return (ERROR);
    while (1) {
        pause();
        if (sig_counter(-1) == 0)
            break;
        *status = sig_counter(-1);
    }
    return (SUCCESS); 
}

void receive_pos(int *x, int *y)
{
    sig_counter(0);
    while (1) {
        pause();
        if (sig_counter(-1) == 0)
            break;
        *x = sig_counter(-1);
    }
    sig_counter(0);
    while (1) { 
        pause();
        if (sig_counter(-1) == 0)
            break;
        *y = sig_counter(-1);
    }
}
