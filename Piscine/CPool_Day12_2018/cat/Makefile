##
## EPITECH PROJECT, 2018
## make file for do op
## File description:
## make fill for do op
##

SRC	=	main.c		\

OBJ 	=	$(SRC:.c=.o)

NAME 	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(SRC) -I../include/ -L../lib/my -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C ../lib/my
	rm -f $(NAME)


re: fclean all
