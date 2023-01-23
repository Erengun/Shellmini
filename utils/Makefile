SRCS        :=      ft_atoi2.c \
                          ft_between_chars.c \
                          ft_chartostr.c \
                          ft_countchar.c \
                          ft_dup_matrix.c \
                          ft_extend_matrix.c \
                          ft_free_matrix.c \
                          ft_isspace.c \
                          ft_lsttomatrix.c \
                          ft_matrix_replace_in.c \
                          ft_matrixlen.c \
                          ft_matrixtolst.c \
                          ft_nbrlen.c \
                          ft_putmatrix_fd.c \
                          ft_putnbr_base_fd.c \
                          ft_putnchar_fd.c \
                          ft_putstrn_fd.c \
                          ft_recursive_power.c \
                          ft_sqrt.c \
                          ft_strchars_i.c \
                          ft_strchr_i.c \
                          ft_strenlarge.c \
                          ft_strrncmp.c \
                          ft_subsplit.c \
                          ft_uitoa.c \
                          
NAME=utils.a
LIBFT=../libft/libft.a
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ../libft
	cp ../libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


