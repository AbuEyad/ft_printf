SRCS	= ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_itoa.c ft_strlen.c

# SRCSB =	ft_lstnew.c	

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

# OBJSB = $(SRCSB:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	# cd libft && $(MAKE)

# bonus: $(OBJSB)
# 	ar rcs $(NAME) $(OBJSB)

clean:
	rm -rf $(OBJS) $(OBJSB)
	# cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	# cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re