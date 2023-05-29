/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** main
*/

#include "matchstick.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    return (matchstick(argc, argv));
}