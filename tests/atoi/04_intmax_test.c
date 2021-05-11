#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	intmax_test_atoi(void)
{
	char	s[64];

	sprintf(s, "%d", INT_MAX);
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
