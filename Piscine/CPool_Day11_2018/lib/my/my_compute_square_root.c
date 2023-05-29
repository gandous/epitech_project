/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** calcaule root square of a number
*/

int my_compute_square_root(int nb)
{
    long number = 0;
    int square = 0;
    int minnb = 46345;

    if (nb <= 0) {
        return (0);
    }
    while ((number > 0 || square < minnb) && number != nb) {
        number = square * square;
        square++;
    }
    square--;
    number = square * square;
    if (number == nb) {
        return (square);
    } else {
        return (0);
    }
}
