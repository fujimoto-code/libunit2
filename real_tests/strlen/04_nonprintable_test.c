#include "../../libft/libft.h"
#include <string.h>

int	nonprintable_test_strlen(void)
{
	char	*s;

	s = "\n\n\n\n\t\t\t\r\r\r\r\r\r\r\n\n\n\r\t\t\t\t\t";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
