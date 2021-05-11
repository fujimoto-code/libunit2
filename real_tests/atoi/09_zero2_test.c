#include "../../libft/libft.h"
#include <stdlib.h>

int	zero2_test_atoi(void)
{
	char	*s;

	s = "  +--+++42";
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
