#include "../../libft/libft.h"
#include <string.h>

int	null_test_strlen(void)
{
	if (ft_strlen(NULL) == strlen(NULL))
		return (0);
	else
		return (-1);
}
