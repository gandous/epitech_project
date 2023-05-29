/*
** EPITECH PROJECT, 2018
** header
** File description:
** header file 2
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

void afficher_list(linked_list *list)
{
    linked_list *temp = list;

    while (list->data == '0' && list->next != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    while (list != NULL) {
        my_putchar(list->data);
        temp = list;
        list = list->next;
        free(temp);
    }
    my_putchar('\n');
}

linked_list *add_element(linked_list *list, char valeur)
{
    linked_list *temp_list =  malloc(sizeof(linked_list));

    if (temp_list == NULL)
        return (NULL);
    temp_list->data = valeur;
    temp_list->next = list;
    return (temp_list);
}

int condition_while(char *nb1, char *nb2, long size1, long size2)
{
    if (size1 < 0)
        size1 = -1;
    if (size2 < 0)
        size2 = -1;
    if ((nb1[size1] != '-' && size1 >= 0) || (nb2[size2] != '-' && size2 >= 0)){
        return (1);
    } else {
        return (0);
    }
    return (0);
}

int nb_neg(char *nb1, char *nb2)
{
    int nb_signe = 0;

    if (nb1[0] == '-') {
        nb_signe += 1;
    }
    if (nb2[0] == '-') {
        nb_signe += 1;
    }
    return (nb_signe);
}

int next_nb(char *nb1, char *nb2, long size1, long size2)
{
    int nombre1;
    int nombre2;

    if (size1 < 0 || nb1[size1] == '-' ) {
	nombre1 = 48;
    } else {
        nombre1 = nb1[size1];
    }
    if (size2 < 0 || nb2[size2] == '-') {
        nombre2 = 48;
    } else {
        nombre2 = nb2[size2];
    }
    return (nombre1 + nombre2 - 48*2);
}
