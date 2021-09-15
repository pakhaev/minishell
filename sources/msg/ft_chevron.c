/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:54 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:07:57 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			parse_first_chevron_extra(t_msg *msg)
{
	int	i;

	i = 0;
	while (msg->argv[i] && (!ft_strncmp(msg->argv[i], ">", 1) ||
		!ft_strncmp(msg->argv[i], "<", ft_strlen(msg->argv[i]))))
		i += 2;
	return (i);
}

void		parse_first_chevron(t_msg *msg)
{
	int		i;

	if (!msg->count)
	{
		msg->msg = NULL;
		return ;
	}
	i = parse_first_chevron_extra(msg);
	(i == 2) ? i = 0 : 0;
	if (!msg->argv[i])
		msg->msg = NULL;
	else
		(!(msg->msg = ft_strdup(msg->argv[i]))) \
		? ft_error("parse_first_chevron", -1) : 0;
}

int			ft_count_space(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int			ft_is_double_char(char *s, int i, char sym)
{
	if ((s[i] == '|' || s[i] == ';') && (sym == '|' ||
		sym == ';'))
		return (0);
	if ((sym == '>' && s[i] == '<') || (sym == '<'
		&& s[i] == '>'))
		return (0);
	if (i > 2 && (s[i - 2] == '>' || s[i - 2] == '<') \
	&& ((s[i - 1] == '>' || s[i - 1] == '<') || s[i - 1] == ' ') \
	&& (s[i] == '>' || s[i] == '<'))
		return (0);
	return (1);
}
