/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:23:51 by cimyan            #+#    #+#             */
/*   Updated: 2021/02/24 15:23:54 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			exec_msg(t_msg msg)
{
	pid_t	pid;

	if (builtin_parent(msg))
	{
		free_msg(msg);
		g_mshell.pid = -1;
		return (1);
	}
	else
		pid = fork();
	if (!pid)
		ft_dupclose(msg, 1);
	else if (pid < 0)
		ft_show_error(4, "");
	else if (pid > 0)
		g_mshell.pid = pid;
	ft_dupclose(msg, 0);
	free_msg(msg);
	return (g_mshell.status == 0);
}

void		exec_msg_helper_extra(void)
{
	if (g_mshell.pid == 2)
		enter_status(130);
	else if (g_mshell.pid == 3 || g_mshell.pid == 131)
		enter_status(131);
	else
		enter_status(WEXITSTATUS(g_mshell.pid));
}

void		exec_msg_helper(void)
{
	if (g_mshell.pid < 0)
		return ;
	while (wait(&g_mshell.pid) > 0)
	{
		(void)g_mshell.pid;
	}
	exec_msg_helper_extra();
	g_mshell.pid = 0;
}

void		set_argc(t_msg *msg)
{
	g_mshell.it.i = -1;
	while (msg->argv[++g_mshell.it.i])
		;
	msg->count = g_mshell.it.i;
}

void		set_escape(char *msg, int i, char c, int *flag)
{
	if (msg[i - 1] == '\\' && msg[i] == '\\')
		msg[i] = 3;
	else
	{
		msg[i - 1] = 3;
		msg[i] = c;
	}
	*flag = 1;
}
