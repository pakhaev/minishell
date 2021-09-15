/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:25:01 by cimyan            #+#    #+#             */
/*   Updated: 2021/02/24 15:25:03 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			ft_dstrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char		*rethrow(char **str, int len)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	k = -1;
	i = -1;
	j = 0;
	if (!(res = (char *)ft_calloc(sizeof(char), len + 1)))
		ft_error("rethrow", -1);
	while (str[++i])
	{
		k = -1;
		while (str[i][++k])
			res[j++] = str[i][k];
	}
	return (res);
}

char		*join_splits(char **strs)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	while (strs[++i])
	{
		k = -1;
		while (strs[i][++k])
			j++;
	}
	return (rethrow(strs, j));
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void		come_to_the_darkside(char *file_name, char **paths)
{
	freed(file_name);
	free_double(paths);
}
