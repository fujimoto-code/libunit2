NAME	=	libunit.a
SRCDIR	=	srcs
SRCS	=	$(SRCDIR)/libunit.c $(SRCDIR)/utils.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	ar -src $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all
