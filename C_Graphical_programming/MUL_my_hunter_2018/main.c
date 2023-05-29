/*
** EPITECH PROJECT, 2018
** bootstrap my hunter
** File description:
** main
*/

#include <unistd.h>
#include "my_hunter.h"

int main(int argc, char **argv)
{
    if (argc != 1) {
        write(1, "Duck Hunt\n", 10);
        return (0);
    }
    game();
    return (0);
}
