/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:18:47 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:23:30 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*get_env_extra(char *val)
{
	char	**env;
	char	*tmp;
	char	**res;

	env = g_mshell.envp;
	while (*env)
	{
		(!(res = ft_split(*env, '='))) ? ft_error("get_env_ex1", -1) : 0;
		if (!ft_strcmp(res[0], val))
		{
			if (res[1])
				(!(tmp = ft_strdup(res[1]))) ? ft_error("get_env_ex2", -1) : 0;
			else
				(!(tmp = ft_strdup(""))) ? ft_error("get_env_ex3", -1) : 0;
			free_double(res);
			freed(val);
			return (tmp);
		}
		free_double(res);
		env++;
	}
	freed(val);
	return (NULL);
}

char		*get_env(char *var)
{
	char	*key;
	char	*tmp;

	key = ft_strdup(var);
	tmp = get_env_extra(key);
	return (tmp) ? tmp : NULL;
}

int			get_env_index_extra(char *val)
{
	int i;

	i = 0;
	while (g_mshell.envp[i])
	{
		if (!ft_strncmp(g_mshell.envp[i], val, ft_strlen(val)))
		{
			freed(val);
			return (i);
		}
		++i;
	}
	freed(val);
	return (-1);
}

int			get_env_index(char *var)
{
	int		res;
	char	*key;

	res = 0;
	key = ft_strdup(var);
	res = get_env_index_extra(key);
	return (res) ? res : -1;
}
