# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 11:39:27 by habu-zua          #+#    #+#              #
#    Updated: 2023/08/21 16:22:39 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_putchar_plus.c ft_putnbr_plus.c ft_putstr_plus.c ft_put_hex.c ft_put_u_int.c ft_put_ptr.c\
			ft_itoa.c

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c ft_printf.h
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re