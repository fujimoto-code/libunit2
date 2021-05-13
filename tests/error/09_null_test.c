#include "basic_tests_error.h"

int	null_test09(void)
{
	t_unit_test *testlist;
	int backup;
	int pid;

	testlist = NULL;
	backup = error_test_constructor();
	pid = fork();
	if (pid == 0)
	{
		load_test(&testlist, "Error test", &error_test);
		load_test(&testlist, "Error test", &error_test);
		load_test(NULL, NULL, &error_test);
		launch_tests(&testlist);
		exit(0);
	}
	return (error_test_destructor(backup));
}
