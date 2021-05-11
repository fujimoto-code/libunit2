#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef LOGGING_H
#  define LOGGING_H
#  define RESET "\033[0m"
#  define BOLD "\033[1m"
#  define BLACK "\033[30m"
#  define RED "\033[31m"
#  define GREEN "\033[32m"
#  define YELLOW "\033[33m"
#  define BLUE "\033[34m"
#  define MAGENTA "\033[35m"
#  define CYAN "\033[36m"
#  define WHITE "\033[37m"
#  define BOLDBLACK "\033[1m\033[30m"
#  define BOLDRED "\033[1m\033[31m"
#  define BOLDGREEN "\033[1m\033[32m"
#  define BOLDYELLOW "\033[1m\033[33m"
#  define BOLDBLUE "\033[1m\033[34m"
#  define BOLDMAGENTA "\033[1m\033[35m"
#  define BOLDCYAN "\033[1m\033[36m"
#  define BOLDWHITE "\033[1m\033[37m"
# endif

typedef struct s_unit_test
{
	char				*message;
	struct s_unit_test	*next;
	int					(*f)(void);
}						t_unit_test;

// Prototypes
void	ft_lstclear(t_unit_test **lst);
void	load_test(t_unit_test **lst, char *msg, int (*f)(void));
int		launch_tests(t_unit_test **lst);

#endif
