#ifndef LIBUNIT_H
#define LIBUNIT_H

#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct s_unit_test {
	char *message;
	struct s_unit_test *next;
	int (*f)(void);
}	t_unit_test;

int	launch_tests(t_unit_test **lst);
void load_test(t_unit_test **lst, char *msg, int (*f)(void));

#endif