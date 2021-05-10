#include "../../libft/libft.h"
#include <string.h>

int null_test(void)
{
	if (ft_strlen(0) == strlen("aaa"))
		return (0);
	else
		return (-1);
}
