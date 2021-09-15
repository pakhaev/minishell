/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:16:31 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:16:34 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			input_output_extra(t_msg *msgs)
{
	int		i;

	i = 0;
	while (msgs[i].msg)
		i++;
	return (i);
}

void		add_output_io_extra(int i, int result, t_msg *msgs)
{
	(i == result - 1) ? add_output(msgs[i].out, 1) : 0;
	add_output(msgs[i].out, -1);
}

void		input_output(t_msg *msgs)
{
	int	result;
	int	i;
	int	fd[2];

	result = input_output_extra(msgs);
	i = -1;
	while (++i < result)
	{
		if (i)
		{
			pipe(fd);
			add_output(msgs[i - 1].out, fd[1]);
			msgs[i].in = fd[0];
		}
		add_output_io_extra(i, result, msgs);
	}
}

void		add_output(int *fds, int fd)
{
	int i;

	i = -1;
	while (fds[++i] != -1)
		;
	fds[i] = fd;
}

void		ft_dupclose(t_msg msg, int flag)
{
	int result;

	g_mshell.it.i = -1;
	(msg.in != 0 && flag) ? dup2(msg.in, 0) : 0;
	(msg.in != 0 && !flag) ? close(msg.in) : 0;
	while (msg.out[++g_mshell.it.i] != -1)
	{
		if (flag)
		{
			if (msg.out[g_mshell.it.i] != 1)
				dup2(msg.out[g_mshell.it.i], 1);
			if (!builtin(msg))
			{
				(msg.in < 0) ? exit(1) : 0;
				msg.msg_abs = get_path(msg.msg);
				result = (!msg.msg_abs) \
				? -1 : execve(msg.msg_abs, msg.argv, g_mshell.envp);
				(result < 0) ? ft_show_error(3, msg.msg) : 0;
			}
		}
		else
			(msg.out[g_mshell.it.i] != 1) ? close(msg.out[g_mshell.it.i]) : 0;
	}
}
