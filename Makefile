# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 19:33:19 by gade-oli          #+#    #+#              #
#    Updated: 2024/06/21 15:50:08 by gade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors----------------------------------------------------------

RED 	= '\033[1;31m'
GREEN   = '\033[1;32m'
BLUE    = '\033[1;34m'
RESET   = '\033[0;0m'

#variables-------------------------------------------------------

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = megalibft/
LIBFT = $(LIBFT_DIR)megalibft.a

SRC = src/main.c src/stack/stack.c src/stack/sp.c

BIN = $(SRC:src/%.c=bin/%.o)

#recipes---------------------------------------------------------

all:	$(NAME)
	@echo $(GREEN)"$(NAME) compiled!"$(RESET)

bin/%.o: src/%.c
	@echo $(BLUE)"compiling binaries..."$(RESET)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo $(BLUE)"compiling libft"$(RESET)
	@make --directory=$(LIBFT_DIR) all

$(NAME):	$(LIBFT) $(BIN)
	$(CC) $(CFLAGS) $(LIBFT) $(BIN) -o $(NAME)

clean:
	@echo $(RED)"deleting binaries"$(RESET)
	rm -rf $(BIN)

fclean: clean
	@echo $(RED)"$(NAME) deleted!"$(RESET)
	rm -rf $(NAME)

re:	fclean re

.PHONY: all clean fclean re

#delete---------------------------------------------------------------------------------------------------

test_stack: test/stack_test.c
	$(CC) $(CFLAGS) test/stack_test.c src/stack/stack.c src/stack/stack_utils.c


test_movement: test/movement_test.c
	$(CC) $(CFLAGS) test/movement_test.c src/stack/sp.c src/stack/stack.c src/stack/stack_utils.c
