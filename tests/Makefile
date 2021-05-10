NAME	=	libunit.a
SRCDIR	=	srcs
SRCS	=	main.c ${wildcard strlen/*.c}
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc $(CFLAGS)

FRAMEWORK = ./../framework
FRAMEWORKNAME = libunit.a
FRAMEWORKMAKE  = ${MAKE} -C ${FRAMEWORK} 

LIBFT = ./../libft
LIBFTNAME = libft.a
LIBFTMAKE = ${MAKE} -C ${LIBFT}

all: $(NAME)

%.o: %.c
	$(CC) -c $^ -o $@

$(NAME): $(OBJS)
	${FRAMEWORKMAKE}
	${LIBFTMAKE}
	cp ${FRAMEWORK}/${FRAMEWORKNAME} ./
	cp ${LIBFT}/${LIBFTNAME} ./
	${CC} -o tests ${OBJS} ${LIBFTNAME} ${FRAMEWORKNAME} 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all
