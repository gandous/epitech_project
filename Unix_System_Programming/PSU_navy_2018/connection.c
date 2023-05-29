/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connection inter terminal
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "navy.h"

static void hdl(int sig, siginfo_t *siginfo, void *context)
{
    sig_counter(siginfo->si_pid);
}

static int set_sigaction_connection(void)
{
    struct sigaction act;

    act.sa_sigaction = &hdl;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &act, NULL) < 0)
        return (ERROR);
}

static int create_game(pid_t *pid_usr)
{
    mputstr("my_pid: ");
    mputnbr(getpid());
    mputstr("\nwaiting for enemy connection...\n\n");
    while (1) {
        usleep(20000);
        pause();
        if ((*pid_usr = sig_counter(-1)) != 0)
            break;
    }
    kill(*pid_usr, SIGUSR1);
    usleep(20000);
    mputstr("enemy connected\n\n");
    return (SUCCESS);
}

static int join_game(pid_t pid_usr)
{
    mputstr("my_pid: ");
    mputnbr((int)getpid());
    mputstr("\n");
    kill(pid_usr, SIGUSR1);
    usleep(20000);
    if ((int)pid_usr == sig_counter(-1)) {
        mputstr("successfully connected\n\n");
        return (SUCCESS);
    }
    return (ERROR);
}

int connection(int ac, char **av, pid_t *pid_usr)
{
    if (set_sigaction_connection() == ERROR)
        return (ERROR);
    if (ac == 2)
        if (create_game(pid_usr) == ERROR)
            return (ERROR);
    if (ac == 3) {
        *pid_usr = mgetnbr(av[1]);
        if (join_game(*pid_usr) == ERROR)
            return (ERROR);
    }
    sig_counter(0);
    return (SUCCESS);
}
