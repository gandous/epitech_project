##
## EPITECH PROJECT, 2018
## my ls | Makefile
## File description:
## Makefile
##

NAME	=	my_exec

SRC	=	        main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./include

all:			$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC) $(CFLAGS)
		gcc -o $(NAME) -g3 $(CFLAGS) $(OBJ)
		rm $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
