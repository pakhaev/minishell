/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:55 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:08:58 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			ft_esc_backsl(int i, char *cmd, int quote, int dquote)
{
	int		flag;

	flag = 0;
	if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == '\\' && !quote)
		set_escape(cmd, i, 3, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == '$' && !quote)
		set_escape(cmd, i, 4, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == ';' && !quote && !dquote)
		set_escape(cmd, i, 2, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == '|' && !quote && !dquote)
		set_escape(cmd, i, 5, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == ' ' && !quote && !dquote)
		set_escape(cmd, i, 6, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == '>' && !quote && !dquote)
		set_escape(cmd, i, 7, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && cmd[i] == '<' && !quote && !dquote)
		set_escape(cmd, i, 8, &flag);
	else if (i > 0 && cmd[i - 1] == '\\' && !quote && !dquote)
		set_escape(cmd, i, cmd[i], &flag);
	return (flag);
}

char		*new_str(char *full, char *key, int start, int end)
{
	char	*left;
	char	*right;
	char	*var;
	char	*buffer;
	char	*result;

	var = get_env(key);
	(!(left = ft_substr(full, 0, start))) ? ft_error("", -1) : 0;
	(!(buffer = ft_strjoin(left, var))) ? ft_error("", -1) : 0;
	(!(right = ft_substr(full, end, ft_strlen(full) - end))) \
	? ft_error("", -1) : 0;
	(!(result = ft_strjoin(buffer, right))) ? ft_error("", -1) : 0;
	freed(left);
	freed(right);
	freed(var);
	freed(buffer);
	freed(full);
	return (result);
}

void		free_pieces(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		freed(str[i]);
		i++;
	}
	freed(str);
}
