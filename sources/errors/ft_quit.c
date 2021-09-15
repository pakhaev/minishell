/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:17:58 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:23:43 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			ft_check_quit(t_msg msg)
{
	int i;
	int flag;

	i = -1;
	flag = 1;
	while (msg.argv[1][++i])
		if ((msg.argv[1][i] > '9' || msg.argv[1][i] < '0')
		&& msg.argv[1][i] != '-')
			flag = 0;
	return (flag);
}

void		quit_error(char *str, int flag)
{
	if (flag)
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		quit(1, 255);
	}
	else
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		(g_mshell.it.i > 1) ? ft_putstr_fd(&g_mshell.it.c, 2) : 0;
		(g_mshell.it.i < 0) ? ft_putstr_fd("newline", 2)\
		: ft_putstr_fd(&g_mshell.it.c, 2);
		ft_putstr_fd("'\n", 2);
		enter_status(258);
		freed(str);
	}
}

void		quit(int nbr, int status)
{
	free_double(g_mshell.envp);
	ft_putstr_fd("exit", 2);
	(nbr) ? ft_putstr_fd("\n", 2) : 0;
	exit(status);
}
