/*
** EPITECH PROJECT, 2018
** mr_swap
** File description:
** 
*/

void my_swap(int *a, int *b)
{
    int temp = *b;
    
    *b = *a;
    *a = temp;
}
