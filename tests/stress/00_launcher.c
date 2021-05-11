#include "../../framework/includes/libunit.h"
#include "./basic_tests_stress.h"

int	stress_launcher(void)
{
	t_unit_test	*testlist;

	init_count();
	testlist = NULL;
	puts("STRESS :");
	for (size_t i = 0; i < 3000; i++)
	{
		load_test(&testlist, "Basic test", &basic_test_stress);
	}
	return (launch_tests(&testlist));
}
