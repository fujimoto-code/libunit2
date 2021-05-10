NAME	=	libunit.a
SRCDIR	=	srcs
SRCS	=	main.c ${wildcard strlen/*.c}
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc $(CFLAGS)

FRAMEWORK = ./../framework
FRAMEWORKNAME = libunit.a

LIBFT = ./../libft
LIBFTNAME = libft.a

all: $(NAME)

%.o: %.c
	$(CC) -c $^ -o $@

$(NAME): $(OBJS)
	${MAKE} -C ${FRAMEWORK}
	${MAKE} -C ${LIBFT}
	${CC} -o tests ${OBJS} ${LIBFT}/${LIBFTNAME} ${FRAMEWORK}/${FRAMEWORKNAME}

clean:
	${MAKE} clean ${FRAMEWORK}
	${MAKE} clean ${LIBFT}
	rm -f $(OBJS)

fclean: clean
	${MAKE} fclean ${FRAMEWORK}
	${MAKE} fclean ${LIBFT}
	rm -r $(NAME)
	$(RM) tests

re: fclean all

test: all
	./tests
	@$(RM) ./tests

.PHONY: all clean fclean re srcs header test

srcs:
	sed -i -e "1,/src =/ s|src =.*|src =`find . -type f -name "*.c" | tr '\n' ' '`|" Makefile

proto = $(shell cat *.c | grep -e '^\(int\|void\|size_t\|t_.*\|char\|float\|double\|struct\|unsigned\|short\|const\|long\|bool\|signed\)\t' | sed -e 's/$$/;\\n/')

header:
	sed -i -e '/^\(int\|void\|size_t\|t_.*\|char\|float\|double\|struct\|unsigned\|short\|const\|long\|bool\|signed\)\t/d' $(header)
	sed -i -e "/Prototypes$$/a$(proto)" $(header)
	sed -i -e 's/^ //' $(header)
