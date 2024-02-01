NAME	=	philo

LIBFT	=	libft/libft.a

SRCS	=	main.c \
			setup.c \
			ft_time.c

INC		=	philosophers.h \
			philo_struct.h

OBJS	= $(addprefix srcs/,$(SRCS:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror# -fsanitize=thread -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		make -C libft all

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
