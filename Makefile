# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 19:33:19 by gade-oli          #+#    #+#              #
#    Updated: 2024/06/21 18:40:25 by gade-oli         ###   ########.fr        #
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

SRC = src/main.c src/stack.c src/movements.c src/stack_utils.c src/create_stack.c

BIN = $(SRC:src/%.c=bin/%.o)

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

.PHONY: all clean fclean re

#delete---------------------------------------------------------------------------------------------------

test_stack: test/stack_test.c
	$(CC) $(CFLAGS) test/stack_test.c src/stack/stack.c src/stack/stack_utils.c


test_movement: test/movement_test.c
	$(CC) $(CFLAGS) test/movement_test.c src/stack/sp.c src/stack/stack.c src/stack/stack_utils.c
