/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** header
*/

#define PI     3.141592

#define SUCCESS     0
#define ERROR       84

#ifndef ARCHITECT
#define ARCHITECT

int usage(int);
void display_error(char *msg);
void display_matrix(float **matrix);
float **translate(int ac, int *index, char **av, float **matrix1);
float **scale(int ac, int *index, char **av, float **matrix1);
float **rotate(int ac, int *index, char **av, float **matrix1);
float **reflecte(int ac, int *index, char **av, float **matrix1);
int is_number(char *nbr);
float **xy_matrix(char **av);
float **translation_matrix(char **av, int *flag);
float **scaling_matrix(char **av, int *flag);
float **rotation_matrix(char **av, int *flag);
float **reflection_matrix(char **av, int *flag);
float **create_matrix(int x, int y);
void free_matrix(float **matrix, int height);
float **calc_matrix(float **first_matrix, float **matrix);
float **calc_matrix_final(float **, float **);
void display_result(float x_deb, float y_deb, float x_end, float y_end);
void architect(int ac, char **av);
int error_gestion(int ac, char **av);

#endif
