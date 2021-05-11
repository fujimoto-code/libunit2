#include "../includes/libunit.h"
int		g_ok_count;
int		g_count;

static void	print_status(int status, t_unit_test *tmp)
{
	if (WIFEXITED(status))
	{
		printf("> %s", BLUE "[OK]  " RESET);
		g_ok_count++;
	}
	else if (WTERMSIG(status) == SIGSEGV)
		printf("> %s", RED "[SEGV]" RESET);
	else if (WTERMSIG(status) == SIGBUS)
		printf("> %s", RED "[BUSE]" RESET);
	else
		printf("> %s", RED "[KO]  " RESET);
	printf(" : %s\n", tmp->message);
}

int	launch_tests(t_unit_test **lst)
{
	t_unit_test	*tmp;
	pid_t		pid;
	int			signal;

	if (!lst || !*lst)
		return (-1);
	tmp = *lst;
	while (tmp)
	{
		g_count++;
		pid = fork();
		if (pid == -1)
		{
			printf("fork error!\n");
			break ;
		}
		if (pid == 0)
			exit(tmp->f());
		wait(&signal);
		print_status(signal, tmp);
		tmp = tmp->next;
	}
	printf("%d/%d tests checked\n", g_ok_count, g_count);
	ft_lstclear(lst);
	return (1);
}

void	load_test(t_unit_test **lst, char *msg, int (*f)(void))
{
	t_unit_test	*newlst;
	t_unit_test	*tmp;

	newlst = malloc(sizeof(t_unit_test));
	if (!newlst)
	{
		ft_lstclear(lst);
		printf("xmalloc: allocating error");
		exit(-1);
	}
	newlst->f = f;
	newlst->message = msg;
	newlst->next = NULL;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newlst;
	}
	else
		*lst = newlst;
}
