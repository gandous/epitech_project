/*
** EPITECH PROJECT, 2018
** init table
** File description:
** set table value to 0
*/

char *init_table(char *table, int size)
{
    for (int index = 0 ; index < size ; index++) {
        table[index] = '0';
    }
    return (table);
}
