/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:05:48 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/09 16:05:50 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		enter_status(int nb)
{
	char	*str;
	char	*nstr;

	(!(str = ft_itoa(nb))) ? ft_error("enter_status 1", -1) : 0;
	g_mshell.status = nb;
	(!(nstr = ft_strjoin("?=", str))) ? ft_error("enter_status 2", -1) : 0;
	add_env(nstr);
	freed(nstr);
	freed(str);
}

char		**add_env_extra(char *var)
{
	char	**env;
	int		i;

	i = -1;
	if (!(env = (char **)ft_calloc(sizeof(char *),\
		ft_dstrlen(g_mshell.envp) + 2)))
		ft_error("add_env_extra 1", -1);
	while (g_mshell.envp[++i])
		(!(env[i] = ft_strjoin(g_mshell.envp[i], ""))) \
		? ft_error("add_env_extra 2", -1) : 0;
	(!(env[i] = ft_strjoin(var, ""))) ? ft_error("add_env_extra 3", -1) : 0;
	free_double(g_mshell.envp);
	return (env);
}

void		add_env(char *str)
{
	char	**splinter;
	char	*var;
	char	*ps;

	(!(splinter = ft_split(str, '='))) ? ft_error("add_env", -1) : 0;
	var = add_env_sign(str, splinter[0], splinter[1]);
	delete_env(splinter[0]);
	g_mshell.envp = add_env_extra(var);
	ps = ft_strchr(str, '=');
	if (ps && *--ps == '+')
		(var) ? freed(var) : 0;
	(splinter) ? free_double(splinter) : 0;
}

char		**delete_env_extra(int pos)
{
	char	**nstr;

	g_mshell.it.i = -1;
	g_mshell.it.j = -1;
	if (!(nstr = (char **)ft_calloc(sizeof(char *),\
		ft_dstrlen(g_mshell.envp) + 1)))
		ft_error("delete_env_extra 1", -1);
	while (g_mshell.envp[++g_mshell.it.i])
		if (g_mshell.it.i != pos)
			(!(nstr[++g_mshell.it.j] = ft_strdup(g_mshell.envp\
			[g_mshell.it.i]))) ? ft_error("delete_env_extra 2", -1) : 0;
	free_double(g_mshell.envp);
	return (nstr);
}

void		delete_env(char *str)
{
	int		position;

	position = get_env_index(str);
	if (position == -1)
		return ;
	g_mshell.envp = delete_env_extra(position);
}
