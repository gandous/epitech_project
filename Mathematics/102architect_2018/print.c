/*
** EPITECH PROJECT, 2018
** all function for print
** File description:
** file for printing function
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int usage(int usage)
{
    printf("USAGE\n");
    printf("   ./102architect x y transfo1 arg11 [arg12] [transfo2 ");
    printf("arg12 [arg22]] ...\n\n");
    printf("DESCRIPTION\n");
    printf("   x\tabscissa of the original point\n");
    printf("   y\tordinate of the original point\n\n");
    printf("   transfo arg1 [arg2]\n");
    printf("   -t i j\ntranslation along vector (i, j)\n");
    printf("   -z m n\tscaling by factors m (x-axis) and n (y-axis)\n");
    printf("   -r d  \trotation centered in O by a d degree angle\n");
    printf("   -s d  \treflection over the axis passing through O with");
    printf(" an inclination\n\t\tangle of d degrees\n");
    return (usage);
}

void display(float nb, int index)
{
    if (-0.000000001 <= nb && nb <= -0.009)
        nb *= -1;
    if (index < 2)
        printf("%.2f\t", nb);
    else
        printf("%.2f\n", nb);
}

void display_matrix(float **matrix)
{
    for (int i = 0 ; i < 3 ; i += 1) {
        for (int ii = 0 ; ii < 3 ; ii += 1) {
            display(matrix[i][ii], ii);
        }
    }
}

void display_error(char *msg)
{
    write(2, msg, strlen(msg));
    exit(84);
}

void display_result(float x_deb, float y_deb, float x_end, float y_end)
{
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x_deb, y_deb, x_end, y_end);
}
