/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:03:52 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/09 16:03:53 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			ft_reparse_msg_flag(char *msg, int i)
{
	if (msg[i] == '>' || msg[i] == '<')
	{
		if (msg[i] == '<')
			return (12);
		else if (msg[i] == '>' && (msg[i + 1] == '>'))
			return (1);
		else if (msg[i] == '>' && (msg[i - 1] == '>'))
			return (12);
		else if (msg[i + 1] != ' ')
			return (12);
		else
			return (1);
	}
	else if (msg[i] != '<' && msg[i + 1] == '<' && msg[i] != ' ')
		return (12);
	else if (msg[i] != '>' && msg[i] != ' ' && msg[i + 1] == '>')
		return (12);
	else
		return (1);
	return (0);
}

int			counts_redirect(char *msg)
{
	int	i;
	int count;
	int flag;

	i = 0;
	count = 0;
	while (msg[++i])
	{
		flag = ft_reparse_msg_flag(msg, i);
		if (flag == 1)
			count++;
		else if (flag == 12)
			count += 2;
	}
	return (count);
}

char		*ft_reparse_msg_extra(char *msg, char *str, int k, int i)
{
	int		flag;

	flag = 0;
	while (msg[i])
	{
		flag = ft_reparse_msg_flag(msg, i);
		if (flag == 1)
			str[k++] = msg[i++];
		else if (flag == 12)
		{
			str[k++] = msg[i++];
			str[k++] = ' ';
		}
	}
	str[k] = '\0';
	return (str);
}

char		*ft_reparse_msg(char *msg)
{
	int		i;
	int		k;
	char	*str;
	char	*tmp;

	tmp = ft_strchr(msg, '>');
	if (ft_strchr(msg, '>') || ft_strchr(msg, '<'))
	{
		k = counts_redirect(msg) + 1;
		if (!(str = (char*)malloc(sizeof(char) *\
		ft_strlen(msg) + k)))
			ft_error("ft_reparse_msg", -1);
		i = 0;
		k = 0;
		str = ft_reparse_msg_extra(msg, str, k, i);
		freed(msg);
		return (str);
	}
	return (msg);
}

void		parse_input_extended(t_msg *msgs, char **commands, int i, int j)
{
	while (commands[i])
	{
		msgs = parse_msg_pipe(commands[i++]);
		j = 0;
		while (msgs[j].msg != NULL)
			exec_msg(msgs[j++]);
		exec_msg_helper();
		freed(msgs);
	}
}
