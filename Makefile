CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = count_words.c ft_is_separator.c ft_split.c push_swap.c stack_a_moves.c parssing.c clean.c helper_function.c move_handler.c stack_b_moves.c sort_five.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)