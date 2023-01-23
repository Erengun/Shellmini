# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egun <egun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 13:38:18 by aperez-b          #+#    #+#              #
#    Updated: 2023/01/23 19:21:36 by egun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Make variables
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
CC = gcc
SRC_DIR = src
UTILS_DIR = utils
UTILS = utils/utils.a
LIBFT = libft/libft.a
NAME = minishell
USERNAME = $(shell whoami)

READLINE_LIB = -L./lib/readline/lib -lreadline
INCLUDES =-Iincludes -I$(LIBFT) -I./lib/readline/include
LIB	= ./lib/.minishell

SRC = main.c builtins.c ft_strtrim_all.c exec.c			\
	  fill_node.c get_params.c ft_cmdtrim.c				\
	  expand.c heredoc.c error.c env.c custom_cmd.c		\
	  get_next_line.c get_next_line_utils.c prompt.c	\
	  ft_cmdsubsplit.c signal.c parse_args.c get_cmd.c

OBJ =  $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

OBJ_LFT = $(addprefix $(OBJ_LFT_DIR)/, $(SRC_LFT:.c=.o))

all: $(LIB) $(NAME)

$(LIB):
	make -C ./lib

$(NAME): compile_libft compile_utils $(OBJ)
	@$(CC) -L/Users/$(USERNAME)/readline/lib $(INCLUDES) $(CFLAGS) $(OBJ) $(LIBFT) $(UTILS) -lreadline -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -I/Users/$(USERNAME)/include $(INCLUDES) $(CFLAGS) -c $< -o $@

compile_libft:
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/omerkarakelle/libft.git; \
	fi
	@make -C libft

compile_utils:
	@make -C ./utils

clean:
	@if [ -d "libft" ]; then \
		make clean -C libft/; \
	fi
	@if [ -d "utils" ]; then \
		make clean -C utils/; \
	fi
	@$(RM) -r $(SRC_DIR)/$(OBJ)

fclean: clean
	@if [ -d "libft" ]; then \
		make fclean -C libft/; \
	fi
	@if [ -d "utils" ]; then \
		make fclean -C utils/; \
	fi
	@$(RM) -r minishell

re: fclean
	@make all

.PHONY: all clean fclean norminette create_dirs test git re
