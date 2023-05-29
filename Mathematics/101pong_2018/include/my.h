/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/

#ifndef PONG
#define PONG

typedef struct coord {
    float x;
    float y;
    float z;
} coord_t;

void print_info(void);
void error_output(char const *);
void display_velocity(coord_t *);
void display_coord(coord_t *, int);
coord_t *get_velocity(coord_t *, coord_t *);
float get_norme(coord_t *);
coord_t *ball_coordinates(coord_t *, coord_t *, float);
void display_point(coord_t *);
float get_angle(coord_t *);
void display_angle(float);
void display_fail(void);
void is_number(char *str);
void only_number(int argc, char **argv);

#endif
