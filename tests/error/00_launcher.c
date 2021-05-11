#include "basic_tests_error.h"
#include "../../framework/includes/libunit.h"

int	error_launcher(void)
{
	t_unit_test	*testlist;

	init_count();
	testlist = NULL;
	puts("ERROR :");
	load_test(NULL, NULL, &error_test);
	if (launch_tests(&testlist) != -1)
		return (0);
	load_test(NULL, "Error test", NULL);
	if (launch_tests(&testlist) != -1)
		return (0);
	load_test(&testlist, NULL, NULL);
	if (launch_tests(&testlist) != -1)
		return (0);
	load_test(NULL, "Error test", &error_test);
	if (launch_tests(&testlist) != -1)
		return (0);
	load_test(&testlist, NULL, &error_test);
	if (launch_tests(&testlist) != -1)
		return (0);
	load_test(&testlist, "Error test", NULL);
	if (launch_tests(&testlist) != -1)
		return (0);
	return (1);
}
