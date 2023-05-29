/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** main for pushswap
*/

#include "pushswap.h"

int main(int argc, char **argv)
{
    if (argc > 1) {
        return (pushswap(argc, argv));
    } else {
        return (84);
    }
}