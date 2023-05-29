/*
** EPITECH PROJECT, 2018
** error
** File description:
** error prototypes
*/

#ifndef ERROR_H
#define ERROR_H

void error_begin_op(char *, char *);
void errors(char *, char **);
void error_parenthesis(char *, char const *);
void error_id(char *, int);
void error_operator1_in_base(char **);
void error_operator_in_base(char *, char *, int);
void unknow_digit(char *);
void error_two_op_in_a_row(char *, char *);
void error_end_op(char *);
void error_base(char *);
void invalid_expression(char *, char *);

#endif
