#include "../includes/libunit.h"

void	print_status(int status, t_unit_test *tmp, int *ok_count)
{
	if (WIFEXITED(status))
	{
		if (!status)
		{
			printf("> %s", BLUE "[OK]  " RESET);
			(*ok_count)++;
		}
		else
			printf("> %s", RED "[KO]  " RESET);
	}
	else if (WTERMSIG(status) == SIGSEGV)
		printf("> %s", RED "[SEGV]" RESET);
	else if (WTERMSIG(status) == SIGBUS)
		printf("> %s", RED "[BUSE]" RESET);
	else
	{
		printf("> %s", RED "[fatal]  " RESET);
		printf(" : %s\n", tmp->message);
		exit(1);
	}
	printf(" : %s\n", tmp->message);
}

int	launch_tests(t_unit_test **lst)
{
	t_unit_test	*tmp;
	int			ok_count;
	int			count;

	ok_count = 0;
	count = 0;
	if (!lst || !*lst)
	{
		write(2, "Invalid argument.\n", 18);
		exit(1);
	}
	tmp = *lst;
	while (tmp)
	{
		count++;
		run_child_process(tmp, &ok_count);
		tmp = tmp->next;
	}
	printf("%d/%d tests checked\n\n\n", ok_count, count);
	ft_lstclear(lst);
	if (ok_count == count)
		return (0);
	return (-1);
}

void	load_test(t_unit_test **lst, char *msg, int (*f)(void))
{
	t_unit_test	*newlst;

	newlst = malloc(sizeof(t_unit_test));
	if (!newlst)
	{
		ft_lstclear(lst);
		write(2, "xmalloc: allocating error", 25);
		exit(1);
	}
	if (!lst || !msg || !f)
	{
		write(2, "Invalid argument.\n", 18);
		exit(1);
	}
	newlst->f = f;
	newlst->message = msg;
	newlst->next = NULL;
	ft_lstadd_front(lst, newlst);
}
