#include "../includes/libunit.h"
int g_ok_count;
int g_count;

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

void	load_test(t_unit_test **lst, char *msg, int (*f)(void))
{
	t_unit_test	*newlst;
	t_unit_test	*tmp;

	newlst = malloc(sizeof(t_unit_test));
	if (!newlst)
	{
		// TODO freeの処理
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
		{
			tmp = tmp->next;
		}
		tmp->next = newlst;
	}
	else
		*lst = newlst;
}

void	print_status(int status)
{
	if (WIFEXITED(status))
	{
		printf("> %s", BLUE"[OK]  "RESET);
		g_ok_count++;
	}
	else if (WTERMSIG(status) == SIGSEGV)
		printf("> %s",  RED"[SEGV]"RESET);
	else if (WTERMSIG(status) == SIGBUS)
		printf("> %s",  RED"[BUSE]"RESET);
	else
		printf("> %s",  RED"[KO]  "RESET);
}

int		launch_tests(t_unit_test **lst)
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
		{
			exit(tmp->f());
		}
		wait(&signal);
		print_status(signal);
		printf(" : %s\n", tmp->message);
		tmp = tmp->next;
	}
	ft_lstclear(lst);
	printf("%d/%d tests checked\n", g_ok_count, g_count);
	return (1);
}
