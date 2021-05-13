#include "../../libft/libft.h"
#include <string.h>

int	empty_test_strlen(void)
{
	char	*s;

	s = "";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
