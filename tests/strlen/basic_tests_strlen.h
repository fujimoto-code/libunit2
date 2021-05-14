#ifndef BASIC_TESTS_STRLEN_H
# define BASIC_TESTS_STRLEN_H

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

int	strlen_launcher(void);
int	basic_test_strlen(void);
int	segv_test_strlen(void);
int	bus_test_strlen(void);
int	ko_test_strlen(void);

#endif
