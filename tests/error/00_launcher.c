#include "basic_tests_error.h"
#include "../../framework/includes/libunit.h"
#include <string.h>

static int	load_test_error(t_unit_test **lst, char *msg, int (*f)(void))
{
	pid_t	pid;
	int		signal;

	pid = fork();
	if (pid == 0)
		load_test(lst, msg, f);
	wait(&signal);
	if (signal != -1)
		return (0);
	return (1);
}

static int	launch_error()
{
	pid_t	pid;
	int		signal;

	pid = fork();
	if (pid == 0)
		launch_tests(NULL);
	wait(&signal);
	if (signal != -1)
		return (0);
	return (1);
}

int	error_launcher(void)
{
	t_unit_test *testlist;
	char buf[256];

	init_count();
	testlist = NULL;
	puts("ERROR :\n");
	setbuf(stdout, buf);
	if (!load_test_error(&testlist, "Error test", NULL))
		return (-1);
	if (!load_test_error(&testlist, NULL, &error_test))
		return (-1);
	if (!load_test_error(NULL, "Error test", &error_test))
		return (-1);
	if (!launch_error())
		return (-1);
	if (strcmp("Invalid argument.\nInvalid argument.\nInvalid argument.\nInvalid argument.\n", buf) != 0)
		return (-1);
	return (0);
}
