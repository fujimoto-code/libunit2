#include "../includes/libunit.h"

extern int	g_ok_count;
extern int	g_count;

void	ft_lstclear(t_unit_test **lst)
{
	t_unit_test	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	init_count(void)
{
	g_count = 0;
	g_ok_count = 0;
}
