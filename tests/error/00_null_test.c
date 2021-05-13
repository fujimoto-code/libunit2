#include "basic_tests_error.h"

int	error_test_constructor(void)
{
	int fd;
	int backup;

	system("echo 'Invalid argument.' > expect");
	backup = dup(STDERR_FILENO);
	fd = open("./output", O_RDWR | O_CREAT, 0777);
	dup2(fd, STDERR_FILENO);
	return (backup);
}

int	error_test_destructor(int backup)
{
	int ret;
	int status;

	dup2(backup, STDERR_FILENO);
	close(backup);
	ret = system("diff output expect");
	system("rm output expect");
	wait(&status);
	return (!status && ret);
}

int	error_test(void)
{
	return (0);
}

int	null_test00(void)
{
	t_unit_test *testlist;
	int backup;
	int pid;

	testlist = NULL;
	backup = error_test_constructor();
	pid = fork();
	if (pid == 0)
	{
		load_test(&testlist, "Error test", NULL);
		exit(0);
	}
	return (error_test_destructor(backup));
}
