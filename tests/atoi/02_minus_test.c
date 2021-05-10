#include "basic_tests.h"
#include "../../libft/libft.h"
#include <stdlib.h>

int minus_test(void)
{
	char *s;

	s = "-42";
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
