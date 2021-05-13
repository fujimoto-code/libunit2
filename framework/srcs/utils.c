#include "../includes/libunit.h"

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

void	run_child_process(t_unit_test *lst, int *ok_count)
{
	pid_t	pid;
	int		signal;

	pid = fork();
	if (pid == -1)
	{
		printf("fork error!\n");
		return ;
	}
	if (pid == 0)
		exit(lst->f());
	wait(&signal);
	print_status(signal, lst, ok_count);
	return ;
}

void	ft_lstadd_front(t_unit_test **lst, t_unit_test *new)
{
	new->next = (*lst);
	(*lst) = new;
}
