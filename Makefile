NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       error.c \
       ft_split.c \
       push_command.c \
       push_swap_command.c \
       push_swap_init.c \
       reverse_rotate_command.c \
       rotate_command.c \
       stack_init.c \
       stack_utils.c \
       swap_command.c \
       tiny_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
