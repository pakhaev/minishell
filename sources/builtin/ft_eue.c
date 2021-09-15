/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:23:08 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 15:00:00 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			builtin(t_msg msg)
{
	if (!ft_strcmp(msg.msg, "echo"))
		ft_show_echo(msg);
	else if (!ft_strcmp(msg.msg, "<"))
		;
	else if (!ft_strcmp(msg.msg, ">>"))
		;
	else if (!ft_strcmp(msg.msg, ">"))
		;
	else if (!ft_strcmp(msg.msg, "pwd"))
		ft_show_pwd();
	else if (!ft_strcmp(msg.msg, "env"))
		ft_show_env(msg, 0);
	else if (!ft_strcmp(msg.msg, "ENV"))
		ft_show_env(msg, 0);
	else
		return (0);
	exit(0);
	return (1);
}

int			builtin_parent(t_msg msg)
{
	int		i;

	i = ft_dstrlen(msg.argv) - 1;
	if (!ft_strcmp(msg.msg, ">") || !ft_strcmp(msg.msg, "<")\
	|| !ft_strcmp(msg.msg, ">>"))
		(!(g_mshell.end_command = ft_strdup("")))\
		? ft_error("built_parent up", -1) : 0;
	else if (msg.argv[i])
		(!(g_mshell.end_command = ft_strdup(msg.argv[i])))\
		? ft_error("built_parent up", -1) : 0;
	update_current_space();
	if (!ft_strcmp(msg.msg, "cd"))
		ft_show_cd(msg);
	else if (!ft_strcmp(msg.msg, "export"))
		ft_show_export(msg);
	else if (!ft_strcmp(msg.msg, "unset"))
		ft_show_unset(msg);
	else if (!ft_strcmp(msg.msg, "exit"))
		ft_exit(msg);
	else
		return (0);
	return (1);
}

void		ft_show_export(t_msg msg)
{
	if (msg.count == 1)
		ft_show_env(msg, 1);
	else
		ft_show_export_extra(msg);
}

void		ft_show_unset(t_msg msg)
{
	if (msg.count == 1)
		ft_show_error(6, "");
	else
		ft_show_unset_extra(msg);
}

void		ft_exit(t_msg msg)
{
	if (msg.count == 1)
		quit(1, g_mshell.status);
	else if (msg.count == 2)
		(ft_check_quit(msg)) ? quit(1, ft_atoi(&msg.argv[1])) \
		: quit_error(msg.argv[1], 1);
	else if (msg.count > 2)
	{
		enter_status(1);
		(ft_check_quit(msg)) ? ft_show_error(9, "") \
		: quit_error(msg.argv[1], 1);
	}
}
