#include "basic_tests_error.h"
#include "../../framework/includes/libunit.h"
#include <string.h>
#include <fcntl.h>

static void pid_error(pid_t pid)
{
	if (pid == -1)
	{
		printf("fork error!\n");
		exit(1);
	}
}

static void print_test_status(void)
{
	int status;

	status = 0;
	wait(&status);
	if (WIFEXITED(status))
	{
		if (!status)
			printf("%s\n","[KO]");
	}
	else if (WTERMSIG(status) == SIGSEGV)
		printf("%s\n","[SEGV]");
	else if (WTERMSIG(status) == SIGBUS)
		printf("%s\n","[BUSE]");
	else
	{
		printf("%s\n","[fatal]");
		exit(1);
	}
}

static void	load_test_error(t_unit_test **lst, char *msg, int (*f)(void))
{
	pid_t	pid;
	pid = fork();

	pid_error(pid);
	if (pid == 0)
	{
		load_test(lst, msg, f);
		exit(0);
	}
	print_test_status();
}

static void	launch_error(t_unit_test **testlist)
{
	pid_t	pid;

	pid = fork();
	pid_error(pid);
	if (pid == 0)
	{
		launch_tests(testlist);
		exit(0);
	}
	print_test_status();
}

static void	launch_error_load()
{
	pid_t	pid;
	t_unit_test *testlist;

	pid = fork();
	pid_error(pid);
	if (pid == 0)
	{
		load_test(&testlist, "Error test", &error_test);
		load_test(&testlist, "Error test", &error_test);
		load_test(NULL, NULL, &error_test);
		launch_tests(&testlist);
		exit(0);
	}
	print_test_status();
}

int	error_launcher(void)
{
	t_unit_test *testlist;
	// t_unit_test *testlist2;
    int backup = dup(STDOUT_FILENO);
    int fd = open("./output", O_RDWR | O_CREAT);
	testlist = NULL;
	puts("ERROR :\n");
	dup2(fd, STDOUT_FILENO);
	load_test_error(&testlist, "Error test", NULL);
	load_test_error(&testlist, NULL, &error_test);
	load_test_error(NULL, "Error test", &error_test);
	load_test_error(NULL, NULL, &error_test);
	load_test_error(&testlist, NULL, NULL);
	launch_error_load();
	launch_error(NULL);
	// launch_error(testlist2);
	dup2(backup, STDOUT_FILENO);
	close(backup);
	system("chmod 777 output");
	system("echo 'Invalid argument.' > expect");
	system("echo 'Invalid argument.' >> expect");
	system("echo 'Invalid argument.' >> expect");
	system("echo 'Invalid argument.' >> expect");
	system("echo 'Invalid argument.' >> expect");
	system("echo 'Invalid argument.' >> expect");
	system("echo 'Invalid argument.' >> expect");
	int ret = system("diff output expect");
	system("rm output expect");
	return (ret);
}
