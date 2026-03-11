# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agkicina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 17:47:53 by agkicina          #+#    #+#              #
#    Updated: 2025/12/29 11:03:17 by agkicina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putchar.c ft_printhex.c ft_printptr.c ft_putnumber.c ft_putstr.c ft_unsigned_int.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
