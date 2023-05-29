##
## EPITECH PROJECT, 2018
## make file for do op
## File description:
## make fill for do op
##

SRC	=	main.c		\
		../lib/libmy.a	\

OBJ 	=	$(SRC:.c=.o)

NAME 	=	do-op

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
