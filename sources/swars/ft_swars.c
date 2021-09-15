/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:09:05 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:09:12 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char			*check_chewie_extra(char *str, char *nstr, int i, int j)
{
	while (str[++i])
	{
		if (str[i] == '$' && (str[i + 1] >= '1' \
		&& str[i + 1] <= '9') && str[i + 2] == ' ')
		{
			(nstr) ? freed(nstr) : 0;
			return (str);
		}
		if (str[i] == '$' && (str[i + 1] >= '1' && str[i + 1] <= '9'))
		{
			nstr[j++] = str[i];
			nstr[j++] = str[i + 1];
			nstr[j++] = ' ';
			i++;
		}
		else
			nstr[j++] = str[i];
	}
	nstr[j] = '\0';
	return (nstr);
}

char			*chewie_chewie(char *str)
{
	int			i;
	int			j;
	char		**split;
	char		*arr[2];

	i = 0;
	while (g_mshell.envp[i])
	{
		(!(split = ft_split(g_mshell.envp[i], '='))) \
		? ft_error("chewie_chewie 1", -1) : 0;
		(!(arr[0] = ft_strdup(split[0]))) \
		? ft_error("chewie_chewie 2", -1) : 0;
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == '$')
				str = new_chewie(str, split[0], arr, j);
			j++;
		}
		i++;
		freed(arr[0]);
		free_double(split);
	}
	return (luke_i_am_your_father(str));
}

char			*chewie_we_are_home(char *str)
{
	char		*nstr;
	int			i;
	int			j;

	if (ft_strchr(str, '$'))
	{
		(!(nstr = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2)))) \
		? ft_error("CHEWIE", -1) : 0;
		i = -1;
		j = 0;
		nstr = check_chewie_extra(str, nstr, i, j);
		(str) ? freed(str) : 0;
		return (nstr);
	}
	return (str);
}

char			*return_father_luke(char **split, char *str)
{
	int			i;
	int			j;
	char		*res[3];
	char		*result;

	res[0] = str;
	j = 0;
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j] && (split[i][j] != '$'
			|| !ft_isalnum(split[i][j + 1])))
			j++;
		(!(res[1] = ft_substr(split[i], 0, j))) ? ft_error("", -1) : 0;
		(!(res[2] = ft_strjoin(res[0], res[1]))) ? ft_error("", -1) : 0;
		freed(res[0]);
		(!(res[0] = ft_strjoin(res[2], ""))) ? ft_error("", -1) : 0;
		freed(res[1]);
		freed(res[2]);
		i++;
	}
	result = ft_strjoin(res[0], " ");
	freed(res[0]);
	return (result);
}

char			*luke_i_am_your_father(char *str)
{
	char		**split;
	char		*nstr;
	char		*res;

	split = ft_split(str, 3);
	(!(nstr = ft_strdup(""))) ? ft_error("luke_i_am_your_father", -1) : 0;
	res = return_father_luke(split, nstr);
	freed(str);
	free_double(split);
	return (res);
}
