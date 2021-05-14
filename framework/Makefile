NAME	=	libunit.a
SRCDIR	=	srcs
SRCS	=	$(SRCDIR)/libunit.c $(SRCDIR)/utils.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

$(NAME): $(OBJS)
	ar -src $(NAME) $(OBJS)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all
