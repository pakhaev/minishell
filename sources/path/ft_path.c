/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:16:37 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:16:40 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char			*use_the_force_luke(char *path, char *msg)
{
	char		*way;

	if (!(way = (char *)ft_calloc(sizeof(char),
		(ft_strlen(msg) + ft_strlen(path) + 2))))
		ft_error("use_the_force_luke", -1);
	way = ft_strcat(way, path);
	way = ft_strcat(way, "/");
	way = ft_strcat(way, msg);
	return (way);
}

char			*get_path_extra(char **paths, char *s2, char *msg)
{
	struct stat	buf;
	int			i;
	char		*s1;

	i = -1;
	while (paths[++i])
	{
		s1 = use_the_force_luke(paths[i], msg);
		if (!stat(s1, &buf))
		{
			come_to_the_darkside(s2, paths);
			return (s1);
		}
		freed(s1);
	}
	come_to_the_darkside(s2, paths);
	return (NULL);
}

char			*get_path(char *msg)
{
	char		**paths;
	char		*nstr;
	char		*str;

	if (!ft_strncmp("./", msg, 2) || !ft_strncmp("/", msg, 1))
		return (get_relative_path(msg));
	str = get_env("PATH");
	if (!str)
		return (NULL);
	(!(paths = ft_split(str, ':'))) ? ft_error("get_path", -1) : 0;
	nstr = get_path_extra(paths, str, msg);
	return (nstr) ? nstr : (NULL);
}

char			*get_relative_path(char *msg)
{
	struct stat	buf;

	return (!stat(msg, &buf)) ? (ft_strjoin(msg, "")) : 0;
}

int				this_is_the_way(int *i, char *sym, int flag)
{
	if (flag && !g_mshell.redirect)
	{
		if (!ft_strcmp(sym, ">"))
			return (1);
		if (!ft_strcmp(sym, ">>"))
			return (2);
		if (!ft_strcmp(sym, "<"))
			return (3);
		return (0);
	}
	if (!flag)
	{
		if (!ft_strcmp(sym, ">"))
			*i = 1;
		else if (!ft_strcmp(sym, ">>"))
			*i = 2;
		else if (!ft_strcmp(sym, "<"))
			*i = 3;
		else
			return (0);
		return (1);
	}
	return (0);
}
