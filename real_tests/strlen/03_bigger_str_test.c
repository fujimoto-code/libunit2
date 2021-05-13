#include "../../libft/libft.h"
#include <string.h>
#include <stdlib.h>

int	bigger_str_test_strlen(void)
{
	char	*str_test;

	str_test = malloc(sizeof(char) * ((size_t)INT32_MAX + 10));
	memset(str_test, 'a', INT32_MAX);
	str_test[INT32_MAX] = 0;
	if (ft_strlen(str_test) == strlen(str_test))
		return (0);
	else
		return (-1);
}
