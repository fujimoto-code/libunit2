#include "../../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	intmin_test_atoi(void)
{
	char	s[64];

	sprintf(s, "%d", INT_MIN);
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
