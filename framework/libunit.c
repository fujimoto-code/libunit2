#include "libunit.h"

void ft_lstclear(t_unit_test **lst)
{
	t_unit_test *tmp;

	if (!lst)
		return;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

void load_test(t_unit_test **lst, char *msg, int (*f)(void))
{
	t_unit_test *newlst;
	t_unit_test *tmp;

	newlst = malloc(sizeof(t_unit_test));
	if (!newlst)
		return;
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

void print_status(int status)
{
	if (status == SIGSEGV)
		printf("[SEGV]\n");
	else if (status == SIGBUS)
		printf("[BUSE]\n");
	else if (status == -1)
		printf("[KO]\n");
	else if (status == 0)
		printf("[OK]\n");
}

int launch_tests(t_unit_test **lst)
{
	t_unit_test *tmp;
	pid_t pid;
	pid_t wait_pid;
	int signal;

	tmp = *lst;
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
			break ;
		if (pid == 0)
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
		tmp = tmp->next;
	}
	ft_lstclear(lst);
	return (1);
}
