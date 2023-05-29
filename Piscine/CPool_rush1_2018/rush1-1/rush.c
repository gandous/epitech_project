/*
** EPITECH PROJECT, 2018
** draw square
** File description:
** draw a square
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_error(void)
{
    write(2, "invalid size\n", 13);
}

void print_line_x(int width)
{
    int x = 0;
    
    my_putchar('|');
    while ((width - 2) > x ) {
        my_putchar(' ');
        x++;
    }
    if (width > 1){
        my_putchar('|');
    }
    my_putchar('\n');
}

void print_ot_line_x(int height)
{
    int x = 0;

    my_putchar('o');
    while ((height -2) > x) {
        my_putchar('-');
        x++;
    }
    if (height > 1) {
        my_putchar('o');
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    int y_index = 0;
    
    if (x <= 0 || y <= 0) {
        print_error();
    }else {
        print_ot_line_x(x);
        while ((y - 2) > y_index) {
            print_line_x(x);
            y_index++;
        }
        if (y > 1) {
            print_ot_line_x(x);
        }
    }
}
