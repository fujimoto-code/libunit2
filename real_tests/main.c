#include "atoi/basic_tests_atoi.h"
#include "strlen/basic_tests_strlen.h"
#include <stdio.h>

int	main(void)
{
	printf(BOLDGREEN "*********************************\n");
	printf("**      42 - Unit Tests      ****\n");
	printf("*********************************\n" RESET);
	strlen_launcher();
	printf("\n\n");
	atoi_launcher();
}
