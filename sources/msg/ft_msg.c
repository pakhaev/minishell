/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:03 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:08:06 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		decrypt_msg_chevrons(t_msg *msg)
{
	g_mshell.it.i = -1;
	while (msg->argv[++g_mshell.it.i])
	{
		g_mshell.it.j = -1;
		while (msg->argv[g_mshell.it.i][++g_mshell.it.j])
		{
			(msg->argv[g_mshell.it.i][g_mshell.it.j] == 7) ?\
			msg->argv[g_mshell.it.i][g_mshell.it.j] = '>' : 0;
			(msg->argv[g_mshell.it.i][g_mshell.it.j] == 8) ?\
			msg->argv[g_mshell.it.i][g_mshell.it.j] = '<' : 0;
		}
	}
}

void		decrypt_msg(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		(str[i] == 1) ? str[i] = ' ' : 0;
		(str[i] == 2) ? str[i] = ';' : 0;
		(str[i] == 4) ? str[i] = '$' : 0;
		(str[i] == 5) ? str[i] = '|' : 0;
		(str[i] == 6) ? str[i] = ' ' : 0;
	}
}

void		get_msg(char **buf)
{
	int		fd;
	char	b[1];
	char	*tmp;
	char	*rd;

	fd = 0;
	tmp = ft_strdup("");
	while (fd == 0)
	{
		fd = get_next_line(1, &rd);
		freed(tmp);
		tmp = ft_strjoin(tmp, rd);
		if (!fd && !ft_strlen(rd))
		{
			freed(rd);
			freed(tmp);
			quit(1, g_mshell.status);
		}
		freed(rd);
		ft_putstr_fd("  \b\b  \b\b", 2);
	}
	*buf = ft_strdup(tmp);
	freed(tmp);
	while (!fd)
		fd = read(1, b, 1);
}

void		enter_msg(char *msg)
{
	int	cite;
	int	dcite;
	int	i;

	cite = 0;
	dcite = 0;
	i = -1;
	while (msg[++i])
	{
		if (i > 0 && msg[i - 1] == '\\' &&
		((msg[i] == '\'' && !dcite && !cite) || (msg[i] == '"' && !cite)))
			msg[i - 1] = 3;
		else if (ft_esc_backsl(i, msg, cite, dcite))
			(void)i;
		else if (msg[i] == '\'')
			get_quote(&cite, &dcite, &msg[i]);
		else if (msg[i] == '"')
			get_dquote(&cite, &dcite, &msg[i]);
		else
			get_letter(cite, dcite, &msg[i]);
	}
}
