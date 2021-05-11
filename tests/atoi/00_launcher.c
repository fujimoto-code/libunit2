#include "../../framework/includes/libunit.h"
#include "basic_tests_atoi.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	puts("ATOI :");
	load_test(&testlist, "Basic test", &basic_test_atoi);
	load_test(&testlist, "MINUS test", &minus_test_atoi);
	load_test(&testlist, "INTMIN test", &intmin_test_atoi);
	load_test(&testlist, "INTMAX test", &intmax_test_atoi);
	load_test(&testlist, "OVERINT test", &overint_test_atoi);
	return (launch_tests(&testlist));
}
