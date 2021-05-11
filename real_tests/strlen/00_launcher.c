#include "../../framework/includes/libunit.h"
#include "basic_tests_strlen.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	init_count();
	testlist = NULL;
	puts("STRLEN :");
	load_test(&testlist, "Basic test", &basic_test_strlen);
	load_test(&testlist, "NULL test", &null_test_strlen);
	load_test(&testlist, "Bigger string test", &bigger_str_test_strlen);
	load_test(&testlist, "Non printable test", &nonprintable_test_strlen);
	load_test(&testlist, "Mix test", &mix_test_strlen);
	load_test(&testlist, "Empty test", &empty_test_strlen);
	return (launch_tests(&testlist));
}
