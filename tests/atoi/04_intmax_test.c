#include "basic_tests.h"
#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int intmax_test(void)
{
	char *s;

	sprintf(s, "%s",INT_MAX);
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
