#include "../../framework/includes/libunit.h"
#include "basic_tests_strlen.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	puts("STRLEN :");
	load_test(&testlist, "Basic test", &basic_test_strlen);
	load_test(&testlist, "SEGV test", &segv_test_strlen);
	load_test(&testlist, "Bus test", &bus_test_strlen);
	load_test(&testlist, "KO test", &ko_test_strlen);
	return (launch_tests(&testlist));
}
