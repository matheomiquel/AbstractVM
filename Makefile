##
## ETNA PROJECT, 10/05/2019 by miquel_m
## octocat
## File description:
##      Makefile
##
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99

NAME    = abstractvm
RM      = rm -f
SRC	= \
	main.c \
	my_putchar.c \
	my_putnbr.c \
	my_putstr.c \
	my_strcmp.c \
	check.c \
	operation.c \
	verification.c \
	gestion.c \
	read.c \
	my_strcat.c \
	my_strlen.c \
	change_type.c\
	my_getnbr.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re