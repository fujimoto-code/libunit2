#include "./atoi/basic_tests_atoi.h"
#include "./strlen/basic_tests_strlen.h"
#include "./stress/basic_tests_stress.h"
#include "./error/basic_tests_error.h"
#include <stdio.h>

int	main(void)
{
	printf(BOLDGREEN"*********************************\n");
	printf("**      42 - Unit Tests      ****\n");
	printf("*********************************\n"RESET);
	strlen_launcher();
	printf("\n\n");
	atoi_launcher();
	stress_launcher();
	if (!error_launcher())
		printf("Error test OK\n");
	else
		printf("Error test KO\n");
}
