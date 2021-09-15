/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:06:18 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/09 16:06:19 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_show_cd_extra(int flag)
{
	char	*path;

	if (!g_mshell.double_status)
	{
		path = (!flag) ? get_env("HOME") : g_mshell.home;
		if (!path)
			ft_show_error(12, "");
		else
		{
			chdir(path);
			enter_status(0);
		}
		(!flag) ? freed(path) : 0;
	}
}

void		sort(char **str)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;
	char	*temp;

	i = 0;
	count = ft_dstrlen(str);
	j = 0;
	while (i <= count && str[i])
	{
		j = i;
		while (++j <= count && str[j])
		{
			if (ft_memcmp(str[i], str[j], ft_strlen(str[j])) > 0)
			{
				temp = (str[i]);
				tmp = str[i];
				str[i] = (str[j]);
				tmp = str[j];
				str[j] = (temp);
			}
		}
		i++;
	}
}

void		ft_show_env_extra(int flag)
{
	int		i;
	char	**str;

	if (flag)
	{
		str = dublicate_env(g_mshell.envp);
		i = -1;
		sort(str);
		while (str[++i])
			ft_show_msg(1, str[i], flag);
		free_double(str);
	}
	else
	{
		i = -1;
		while (g_mshell.envp[++i])
			ft_show_msg(1, g_mshell.envp[i], flag);
	}
	enter_status(0);
}

void		ft_show_export_extra(t_msg msg)
{
	int i;
	int mark;

	i = 0;
	while (++i < msg.count)
	{
		mark = ft_equal_issign(msg.argv[i], 1);
		if (mark == 1)
		{
			add_env(msg.argv[i]);
			enter_status(0);
		}
		else if (mark == -1)
			ft_show_error(5, msg.argv[i]);
		else
			enter_status(0);
	}
}

void		ft_show_unset_extra(t_msg msg)
{
	int i;

	i = 0;
	delete_env("_");
	while (++i < msg.count)
		if (ft_equal_issign(msg.argv[i], 0) == -1)
			ft_show_error(7, "");
		else
		{
			(!g_mshell.double_status) ? delete_env(msg.argv[i]) : 0;
			enter_status(0);
		}
}
