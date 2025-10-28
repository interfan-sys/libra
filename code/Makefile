# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agkicina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 12:06:19 by agkicina          #+#    #+#              #
#    Updated: 2025/10/28 13:35:33 by agkicina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_strlen.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_bzero.c ft_strdup.c ft_substr.c ft_strlcpy.c ft_strjoin.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_toupper.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr.c ft_strrchr.c ft_tolower.c ft_strncmp.c ft_strnstr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

breaker:
			$(CC) -nostartfiles -shared -fPIC -ldl $(CFLAGS) -o libft.so $(SRCS) $(SRCBONUS)

#%.o: %.c
#	$(CC) $(CFLAGS) -C $< -O $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
