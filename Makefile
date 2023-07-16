##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Project_executer
##

SRC	=	$(shell find -name '*.c')

CFLAGS	=	-Wall -Iinclude -lpthread

OBJS	=	$(SRC:.c=.o)

NAME	=	serverJ2T3

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -g -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
