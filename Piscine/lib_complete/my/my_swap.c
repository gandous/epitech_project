/*
** EPITECH PROJECT, 2018
** mr_swap
** File description:
** inverse the value of 2 var
*/

void my_swap(int *a, int *b)
{
    int temp = *b;

    *b = *a;
    *a = temp;
}
