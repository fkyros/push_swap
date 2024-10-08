# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 19:33:19 by gade-oli          #+#    #+#              #
#    Updated: 2024/10/08 17:51:49 by gade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors----------------------------------------------------------

RED 	= '\033[1;31m'
GREEN   = '\033[1;32m'
BLUE    = '\033[1;34m'
RESET   = '\033[0;0m'

#variables-------------------------------------------------------

NAME = push_swap
BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = megalibft/
LIBFT = $(LIBFT_DIR)megalibft.a

SRC = src/main.c \
	src/parser.c \
	src/utils.c \
	src/movements.c \
	src/double_movements.c \
	src/insertion_sort.c \
	src/ksort.c \
	src/sort_stack.c \
	src/sort_utils.c

BIN = $(SRC:src/%.c=bin/%.o)

SRC_BONUS = src/bonus/main_bonus.c

BIN_BONUS = $(SRC_BONUS:src/bonus/%.c=bin/bonus/%.o)

#recipes---------------------------------------------------------

all:	$(NAME)

$(LIBFT):
	@echo $(BLUE)"compiling libft"$(RESET)
	@make --directory=$(LIBFT_DIR) 

bin/%.o: src/%.c
	@echo $(BLUE)"compiling binaries..."$(RESET)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(BIN)
	$(CC) $(CFLAGS) $(BIN) $(LIBFT) -o $@
	@echo $(GREEN)"$(NAME) compiled!"$(RESET)

clean:
	@make clean --directory=$(LIBFT_DIR) 
	rm -rf $(BIN)
	@echo $(RED)"binaries deleted"$(RESET)

fclean: clean
	@make fclean --directory=$(LIBFT_DIR) 
	rm -rf $(NAME)
	@echo $(RED)"$(NAME) deleted!"$(RESET)

re:	fclean all

bonus:	$(LIBFT) $(BIN_BONUS)
	$(CC) $(CFLAGS) $(BIN_BONUS) $(LIBFT) -o $@
	@echo $(GREEN)"$(BONUS) compiled!"$(RESET)

.PHONY: all clean fclean re bonus

#BORRAR: tests-------------------------------------------

movements_test: $(LIBFT)
	$(CC) $(CFLAGS) src/parser.c src/utils.c src/is_sorted.c src/movements.c test/movements_test.c $(LIBFT)
	./a.out
