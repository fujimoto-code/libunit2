NAME	=	libunit.a
SRCDIR	=	srcs
SRCS	=	libunit.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc $(CFLAGS)

all: $(NAME)

%.o: %.c
	$(CC) -c $^ -o $@

$(NAME): $(OBJS)
	ar -src $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all
