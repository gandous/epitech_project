/*
** EPITECH PROJECT, 2019
** navy
** File description:
** set sigaction for the gameloop
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "navy.h"

static void hdl1(int sig)
{
    sig_counter(1);
}

static void hdl2(int sig)
{
    sig_counter(0);
}

int set_sigaction(void)
{
    struct sigaction act1;
    struct sigaction act2;

    act1.sa_handler = &hdl1;
    sigemptyset(&act1.sa_mask);
    act1.sa_flags = 0;
    if (sigaction(SIGUSR1, &act1, NULL) < 0)
        return (ERROR);
    act2.sa_handler = &hdl2;
    sigemptyset(&act2.sa_mask);
    act2.sa_flags = 0;
    if (sigaction(SIGUSR2, &act2, NULL) < 0)
        return (ERROR);
    return (SUCCESS);
}
