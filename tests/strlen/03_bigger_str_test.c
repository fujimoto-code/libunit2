#include "../../libft/libft.h"
#include <string.h>

int	bigger_str_test(void)
{
	char	*s = "test";
	s[0] = '0';
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
