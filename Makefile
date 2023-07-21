COLOUR_GREEN =\033[1;32m
COLOUR_RED =\033[1;31m
COLOUR_YELLOW =\033[1;33m
COLOUR_BLUE =\033[1;34m
NO_COLOUR =\033[0m

CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror

#push_swap---------------------------------------------------

NAME = push_swap

SRC = src/push_swap.c

OBJS = $(SRC.c:.o)

#libft-------------------------------------------------------

LIBFT_DIR = ./libft/

#recipes-----------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(COLOUR_BLUE)compiling libft!$(NO_COLOUR)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(COLOUR_BLUE)compiling puwsh_swap!$(NO_COLOUR)"
	#como compilar????
	@echo "$(COLOUR_GREEN)compiled!$(NO_COLOUR)"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@echo "$(COLOUR_RED)libft objects removed!$(NO_COLOUR)"
	@rm -f $(OBJS)
	@echo "$(COLOUR_RED)push_swap objects removed!$(NO_COLOUR)"
	
fclean:	clean
	@make fclean -s -C $(LIBFT_DIR)
	@echo "$(COLOUR_RED)libft removed!$(NO_COLOUR)"
	@rm -f $(NAME)
	@echo "$(COLOUR_RED)push_swap removed!$(NO_COLOUR)"

re:		fclean all

.PHONY:	all clean fclean re
