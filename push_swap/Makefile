NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       ft_atoi.c \
       ft_split.c \
       check_duplicates.c \
       init_stack_a.c \
       ft_listnew.c \
       ft_listadd_front.c \
       ft_lst_addback.c \
       swap_a.c \
       push_a.c \
       push_b.c \
       rotate_a.c \
       reverse_a.c \
       sort_two.c \
       radix_sort.c \
       indexing.c \
       is_sorted.c \
       stack_size.c \
       sort_three.c \
       sort_five.c \
       ft_is_empty.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re