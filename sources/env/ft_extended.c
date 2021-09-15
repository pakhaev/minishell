/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extended.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:02:39 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/09 16:02:43 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char			*ft_add_bash_extra(char *msg, int count)
{
	int			i;
	int			j;
	char		*nstr;

	i = ft_strlen(msg) + (count * 4) + 1;
	(!(nstr = (char*)malloc(sizeof(char) * i))) ? ft_error("", -1) : 0;
	(!nstr) ? ft_error("KEY", -1) : 0;
	i = -1;
	j = 0;
	while (msg[++i])
	{
		if (msg[i] == '$' && msg[i + 1] == '0')
		{
			i++;
			nstr[j++] = 'b';
			nstr[j++] = 'a';
			nstr[j++] = 's';
			nstr[j++] = 'h';
		}
		else
			nstr[j++] = msg[i];
	}
	nstr[j] = '\0';
	return (nstr);
}

char			*ft_add_bash(char *msg)
{
	int			i;
	int			count;
	char		*nstr;

	count = 0;
	i = -1;
	while (msg[++i])
		(msg[i] == '$' && msg[i + 1] == '0') ? count++ : 0;
	nstr = ft_add_bash_extra(msg, count);
	(msg) ? freed(msg) : 0;
	return (nstr);
}

char			*add_env_sign(char *str, char *s1, char *s2)
{
	char		*before;
	char		*after;
	char		*tmp;
	char		*result;
	char		*new;

	tmp = NULL;
	before = s1;
	result = NULL;
	if (ft_strchr(before, '+'))
	{
		before[ft_strlen(before) - 1] = '\0';
		tmp = get_env(before);
		if (tmp)
			(!(after = ft_strjoin(tmp, s2))) ? ft_error("", -1) : 0;
		else
			(!(after = ft_strdup(s2))) ? ft_error("", -1) : 0;
		(!(new = ft_strjoin(before, "="))) ? ft_error("", -1) : 0;
		(!(result = ft_strjoin(new, after))) ? ft_error("", -1) : 0;
		(after) ? freed(after) : 0;
		(tmp) ? freed(tmp) : 0;
		(new) ? freed(new) : 0;
		return (result);
	}
	return (str);
}
