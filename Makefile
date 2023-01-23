# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egun <egun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 13:38:18 by aperez-b          #+#    #+#              #
#    Updated: 2023/01/23 18:14:05 by egun             ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -MD -g3 
RM = rm -f
CC = gcc
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIBFT = libft/bin/libft.a
BIN = minishell
NAME = $(BIN_DIR)/$(BIN)
USERNAME = $(shell whoami)

READLINE_LIB = -L./lib/readline/lib -lreadline
INCLUDES =-Iincludes -I$(LIBFT) -I./lib/readline/include
LIB	= ./lib/.minishell

SRC = main.c builtins.c ft_strtrim_all.c exec.c			\
	  fill_node.c get_params.c ft_cmdtrim.c				\
	  expand.c heredoc.c error.c env.c custom_cmd.c		\
	  get_next_line.c get_next_line_utils.c prompt.c	\
	  ft_cmdsubsplit.c signal.c parse_args.c get_cmd.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_LFT = $(addprefix $(OBJ_LFT_DIR)/, $(SRC_LFT:.c=.o))

all: $(LIB) $(NAME)

$(LIB):
	make -C ./lib

$(NAME): create_dirs compile_libft $(OBJ)
	@$(CC) -L/Users/$(USERNAME)/readline/lib $(INCLUDES) $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBFT) -lreadline -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -I/Users/$(USERNAME)/include $(INCLUDES) $(CFLAGS) $(CDEBUG) -c $< -o $@

compile_libft:
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/madebypixel02/libft.git; \
	fi
	@make -C libft

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	@if [ -d "libft" ]; then \
		make clean -C libft/; \
	fi
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)

re: fclean
	@make all

.PHONY: all clean fclean norminette create_dirs test git re
