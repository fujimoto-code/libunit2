#include "../../libft/libft.h"
#include <string.h>

int	bigger_str_test_strlen(void)
{
	char	s[256];
	int		i;

	i = -1;
	while (++i != 255)
		s[i] = 'a';
	s[i] = '\0';
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
