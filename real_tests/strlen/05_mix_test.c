#include "../../libft/libft.h"
#include <string.h>

int	mix_test_strlen(void)
{
	char	*s;

	s = "\n\naaaa\n\na\t\t\t\r\r\r\ra\r\r\ar\n\n\n\r\ata\ata\ata\ata\at";
	if (ft_strlen(s) == strlen(s))
		return (0);
	else
		return (-1);
}
