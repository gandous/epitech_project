/*
** EPITECH PROJECT, 2018
** draw rect
** File description:
** 
*/

#include <unistd.h>

void print_error(void)
{
    write(2, "invalid size\n", 13);
}

void print_line_center(int width)
{
    int x = 0;
    
    my_putchar('B');
    while ((width - 2) > x ) {
        my_putchar(' ');
        x++;
    }
    if (width > 1) {
        my_putchar('B');
    }
    my_putchar('\n');
}

void print_first_line(int width, int height)
{
    int x = 0;
    if (width > 1 && height > 1 ) {
        my_putchar('A');        
    } else {   
        my_putchar('B');
    }
    while ((width - 2) > x) {
        my_putchar('B');
        x++;
    }
    if (width > 1 && height > 1) {
        my_putchar('A');
    } else if (width > 1) {
        my_putchar('B');
    }
    my_putchar('\n');
}

void print_last_line(int width2, int height2)
{
    int v = 0;

    if (width2 > 1 && height2 > 1) {
        my_putchar('C');
    } else {
        my_putchar('B');
    }
    while ((width2 -2) > v) {
        my_putchar('B');
        v ++;
    }
    if (width2 > 1) {
        my_putchar('C');
    }
    my_putchar('\n');
} 

void rush(int x, int y)
{
    int y_index = 0;
    
    if (x <= 0 || y <= 0) {
        print_error();
    } else {
        print_first_line(x, y);
        while ((y - 2) > y_index) {
            print_line_center(x);
            y_index++;
        }
        if (y > 1) {
            print_last_line(x, y);
        }
    }
}
