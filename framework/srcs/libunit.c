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

int g_ok_count;

void	load_test(t_unit_test **lst, char *msg, int (*f)(void))
{
	t_unit_test	*newlst;
	t_unit_test	*tmp;

	newlst = malloc(sizeof(t_unit_test));
	if (!newlst)
	{
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

void	print_status(int status)
{
	if (status == SIGSEGV)
		printf("> %s",  RED"[SEGV]"RESET);
	else if (status == SIGBUS)
		printf("> %s",  RED"[BUSE]"RESET);
	else if (status == -1)
		printf("> %s",  RED"[KO]  "RESET);
	else if (status == 0)
	{
		printf("> %s", BLUE"[OK]  "RESET);
		g_ok_count++;
	}
}

int g_count;

int		launch_tests(t_unit_test **lst)
{
	t_unit_test	*tmp;
	pid_t		pid;
	pid_t		wait_pid;
	int			signal;

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
		else if (pid == 0)
		{
			exit(tmp->f());
		}
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp)
	{
		wait_pid = wait(&signal);
		print_status(signal);
		printf(" : %s\n", tmp->message);
		tmp = tmp->next;
	}
	ft_lstclear(lst);

	printf("%d/%d tests checked\n", g_ok_count, g_count);
	return (1);
}
