#include "../../libft/libft.h"
#include <stdlib.h>

int	zero_test_atoi(void)
{
	char	*s;

	s = "0";
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
