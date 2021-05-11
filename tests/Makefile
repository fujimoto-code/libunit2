NAME	= libunit.a
SRCDIR	= srcs
SRCS	= main.c ${wildcard ./strlen/*.c} ${wildcard ./atoi/*.c} ${wildcard ./stress/*.c}
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

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

srcs:
	sed -i -e "1,/src =./main.c ./atoi/01_basic_test.c ./atoi/05_overint_test.c ./atoi/00_launcher.c ./atoi/04_intmax_test.c ./atoi/03_intmin_test.c ./atoi/02_minus_test.c ./strlen/01_basic_test.c ./strlen/03_bigger_str_test.c ./strlen/04_bus_test.c ./strlen/00_launcher.c ./strlen/02_null_test.c ./stress/01_basic_test.c ./stress/00_launcher.c

proto = $(shell cat *.c | grep -e '^\(int\|void\|size_t\|t_.*\|char\|float\|double\|struct\|unsigned\|short\|const\|long\|bool\|signed\)\t' | sed -e 's/$$/;\\n/')

header:
	sed -i -e '/^\(int\|void\|size_t\|t_.*\|char\|float\|double\|struct\|unsigned\|short\|const\|long\|bool\|signed\)\t/d' $(header)
	sed -i -e "/Prototypes$$/a$(proto)" $(header)
	sed -i -e 's/^ //' $(header)
