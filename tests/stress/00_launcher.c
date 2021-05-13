#include "../../framework/includes/libunit.h"
#include "./basic_tests_stress.h"

int	stress_launcher(void)
{
	t_unit_test	*testlist;
	size_t		i;

	i = 0;
	testlist = NULL;
	puts("STRESS :");
	while (i++ < 3)
	{
		load_test(&testlist, "Basic test", &basic_test_stress);
	}
	return (launch_tests(&testlist));
}
