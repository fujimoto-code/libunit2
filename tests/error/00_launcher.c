#include "basic_tests_error.h"

int	error_launcher(void)
{
	t_unit_test *testlist;
	testlist = NULL;
	puts("ERROR :\n");
	load_test(&testlist, "null test 00", &null_test00);
	load_test(&testlist, "null test 01", &null_test01);
	load_test(&testlist, "null test 02", &null_test02);
	load_test(&testlist, "null test 03", &null_test03);
	load_test(&testlist, "null test 04", &null_test04);
	load_test(&testlist, "null test 05", &null_test05);
	load_test(&testlist, "null test 06", &null_test06);
	load_test(&testlist, "null test 07", &null_test07);
	load_test(&testlist, "null test 08", &null_test08);
	load_test(&testlist, "null test 09", &null_test09);
	load_test(&testlist, "null test 10", &null_test10);

	return (launch_tests(&testlist));
}
