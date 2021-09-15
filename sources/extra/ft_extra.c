/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:24:23 by cimyan            #+#    #+#             */
/*   Updated: 2021/02/24 15:24:25 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*ft_strcat(char *s1, char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

int			ft_isspace(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			return (0);
	return (1);
}

void		free_double(char **splits)
{
	int i;

	i = -1;
	while (splits[++i])
		freed(splits[i]);
	freed(splits);
}

void		free_msg(t_msg msg)
{
	int i;

	i = -1;
	while (msg.argv[++i])
		freed(msg.argv[i]);
	freed(msg.msg);
	freed(msg.argv);
	freed(msg.msg_abs);
}

int			red_count(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ';' || str[i] == '|')
			return (count);
		if (str[i] == '>')
			count++;
		i++;
	}
	return (count);
}
