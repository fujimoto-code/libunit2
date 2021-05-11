#include "../../libft/libft.h"
#include <stdlib.h>

int	empty_test_atoi(void)
{
	char	*s;

	s = "";
	if (atoi(s) == ft_atoi(s))
	{
		return (0);
	}
	return (-1);
}
