##
## EPITECH PROJECT, 2018
## bootstrap my hunter | Makefile
## File description:
## Makefile
##

NAME	=	mysh

SRC	=	        main.c\
				minishell.c\
				print.c\
				str_cmp.c\
				command/make_env.c\
				command/make_cd.c\
				get_first_word.c\
				my_str_to_word_array.c\
				array_gest.c\
				str_conc.c\
				array_remove.c\
				command/make_exec.c\
				command/make_exit.c\
				get_number.c\
				command/edit_env.c\
				command/make_default.c\
				text_gest.c

OBJ		=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-I./include -g3

all:			$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -c $(SRC)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re