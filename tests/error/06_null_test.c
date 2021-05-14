#include "basic_tests_error.h"

int	null_test06(void)
{
	t_unit_test	*testlist;
	int			backup;
	int			pid;

	testlist = NULL;
	backup = error_test_constructor();
	pid = fork();
	if (pid == 0)
	{
		load_test(NULL, "Error test", &error_test);
		exit(0);
	}
	return (error_test_destructor(backup));
}
