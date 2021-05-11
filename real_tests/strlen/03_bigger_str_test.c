#include "../../libft/libft.h"
#include <string.h>

int	bigger_str_test_strlen(void)
{
	char	str_test[(size_t)INT32_MAX + 10];

	ft_memset(str_test, 'a', INT32_MAX);
	str_test[INT32_MAX] = 0;
	if (ft_strlen(str_test) == strlen(str_test))
		return (0);
	else
		return (-1);
}
