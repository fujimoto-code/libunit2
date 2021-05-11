#include "../../framework/includes/libunit.h"
#include "basic_tests_atoi.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	init_count();
	testlist = NULL;
	puts("ATOI :");
	load_test(&testlist, "Basic test", &basic_test_atoi);
	load_test(&testlist, "Basic2 test", &basic2_test_atoi);
	load_test(&testlist, "Minus test", &minus_test_atoi);
	load_test(&testlist, "INMIN test", &intmin_test_atoi);
	load_test(&testlist, "INTMAX test", &intmax_test_atoi);
	load_test(&testlist, "OVERINT test", &overint_test_atoi);
	load_test(&testlist, "Empty test", &empty_test_atoi);
	load_test(&testlist, "Zero test", &zero_test_atoi);
	load_test(&testlist, "Zero2 test", &zero2_test_atoi);
	return (launch_tests(&testlist));
}
