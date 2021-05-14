#ifndef BASIC_TESTS_ERROR_H
# define BASIC_TESTS_ERROR_H

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

# include "../../framework/includes/libunit.h"
# include <string.h>
# include <fcntl.h>

int	error_launcher(void);
int	error_test_constructor(void);
int	error_test_destructor(int backup);
int	error_test(void);
int	null_test01(void);
int	null_test02(void);
int	null_test03(void);
int	null_test04(void);
int	null_test05(void);
int	null_test06(void);
int	null_test07(void);
int	null_test08(void);
int	null_test09(void);
int	null_test10(void);
int	null_test11(void);

#endif
