NAME	= libunit.a
SRCDIR	= srcs
SRCS	= main.c ${wildcard ./strlen/*.c} ${wildcard ./atoi/*.c} ${wildcard ./stress/*.c} ${wildcard ./error/*.c}
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

FRAMEWORK = ./../framework
FRAMEWORKNAME = libunit.a

LIBFT = ./../libft
LIBFTNAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C ${FRAMEWORK}
	${MAKE} -C ${LIBFT}
	${CC} -o tests ${OBJS} ${LIBFT}/${LIBFTNAME} ${FRAMEWORK}/${FRAMEWORKNAME}

clean:
	${MAKE} clean -C ${FRAMEWORK}
	${MAKE} clean -C ${LIBFT}
	$(RM) -f $(OBJS)

fclean: clean
	${MAKE} fclean -C ${FRAMEWORK}
	${MAKE} fclean -C ${LIBFT}
	$(RM) -r $(NAME)
	$(RM) tests

re: fclean all

test: all
	./tests
	$(RM) ./tests

.PHONY: all clean fclean re srcs header test
