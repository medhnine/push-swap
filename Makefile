CC = cc
CFLAGS = -Wall -Wextra

SRCS = count_words.c ft_is_separator.c ft_split.c push_swap.c moves.c

OBJS = $(SRCS:.c=.o)

NAME = push.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)