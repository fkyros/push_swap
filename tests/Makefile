CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = ../src/parse.c \
	  ../libft/ft_strlen.c \
	  ../libft/ft_isdigit.c \
	  ../libft/ft_atoi.c

parse: parse_test.c $(SRC)
	$(CC) $(CFLAGS) $(SRC) $< -o $@
