/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cepe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:05 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:23:04 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_show_cd(t_msg msg)
{
	int		check;
	char	str[MAXDIR];
	char	*nstr;

	check = (msg.argv[1] && ft_strchr(msg.argv[1], '~')) ? 1 : 0;
	if (check)
		ft_show_cd_extra(1);
	else if (msg.argv[1])
	{
		if (chdir(msg.argv[1]) < 0)
			ft_show_error(1, msg.argv[1]);
		else
		{
			getcwd(str, MAXDIR);
			nstr = ft_strjoin("PWD=", str);
			add_env(nstr);
			freed(nstr);
		}
	}
	else if (msg.count == 1)
		ft_show_cd_extra(0);
	else
		enter_status(0);
}

void		ft_show_echo(t_msg msg)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 1;
	if (msg.count > 1)
	{
		while (msg.argv[j] && msg.argv[j][0] == '-' &&
				ft_strchr(msg.argv[j] + 1, 'n'))
			j++;
		i += j - 1;
		while (msg.argv[++i])
		{
			ft_putstr_fd(msg.argv[i], 1);
			(msg.argv[i + 1]) ? ft_putstr_fd(" ", 1) : 0;
		}
		(j <= 1) ? ft_putstr_fd("\n", 1) : 0;
	}
	else if (g_mshell.phantom_menace != 1)
		ft_putstr_fd("\n", 2);
}

void		ft_show_pwd(void)
{
	char	str[MAXDIR];

	(!g_mshell.double_status) ? ft_putstr_fd(getcwd(str, MAXDIR), 2) : 0;
	(!g_mshell.double_status) ? ft_putstr_fd("\n", 2) : 0;
}

void		ft_show_env(t_msg msg, int flag)
{
	delete_env("?");
	if (msg.count == 1)
		ft_show_env_extra(flag);
	else
		ft_show_error(8, msg.argv[1]);
}
