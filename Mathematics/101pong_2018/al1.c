/*
** EPITECH PROJECT, 2018
** main file
** File description:
** main file for pong
*/

#include <stdlib.h>
#include "my.h"
#include <math.h>
#include <stdio.h>

coord_t *get_point(char *char_x, char *char_y, char *char_z)
{
    coord_t *point = NULL;

    point = malloc(sizeof(coord_t));
    if (point == NULL)
        return (NULL);
    point->x = atof(char_x);
    point->y = atof(char_y);
    point->z = atof(char_z);
    return (point);
}

void pong_main(char **argv)
{
    float time = atof(argv[7]);
    coord_t *point1 = get_point(argv[1], argv[2], argv[3]);
    coord_t *point2 = get_point(argv[4], argv[5], argv[6]);
    coord_t *velocity = get_velocity(point1, point2);
    coord_t *end_point = ball_coordinates(velocity, point2, time);
    float angle = get_angle(velocity);

    display_velocity(velocity);
    display_coord(end_point, time);
    if ((point2->z < 0 && end_point->z < 0)
        || (point2->z >= 0 && end_point->z >= 0))
        display_fail();
    else if ((point2->z < 0 && end_point->z >= 0)
             || (point2->z >= 0 && end_point->z <0))
        display_angle(angle);
    free(point1);
    free(point2);
    free(velocity);
    free(end_point);
}

int main(int argc, char **argv)
{
    if (argc != 8) {
        print_info();
        return (84);
    }
    only_number(argc, argv);
    pong_main(argv);
    return (0);
}
