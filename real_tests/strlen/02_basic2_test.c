#include "../../libft/libft.h"
#include <string.h>

int	basic2_test_strlen(void)
{
	char	*s;

	s = "1234567()*!!!######";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
