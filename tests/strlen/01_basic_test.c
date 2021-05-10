#include "../../libft/libft.h"
#include <string.h>

int basic_test(void)
{
	if (ft_strlen("Hello") == strlen("Hello"))
		return (0);
	else
		return (-1);
}
