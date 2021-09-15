/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:03:25 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/09 16:03:27 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			check_pipes(char *s, char c)
{
	if (s[0] == c && !s[1] && (s[0] == '>' || s[0] == '<'))
	{
		g_mshell.it.c = c;
		g_mshell.it.i = 0;
		while (s[g_mshell.it.i] == c)
			g_mshell.it.i++;
		return (0);
	}
	else if ((s[0] != '>' && s[0] != '<') && ((s[0] == c && !s[1]) \
	|| (s[0] == c && s[1] != c) || (s[0] == c && s[1] == c)))
	{
		g_mshell.it.c = c;
		g_mshell.it.i = 0;
		while (s[g_mshell.it.i] == c)
			g_mshell.it.i++;
		(c == ')') ? g_mshell.it.i = 1 : 0;
		return (0);
	}
	return (1);
}

char		check_syntax_extra(char *s)
{
	int		sym;
	int		i;

	i = -1;
	sym = 0;
	while (s[++i])
	{
		if (!ft_is_double_char(s, i, sym))
		{
			g_mshell.it.c = s[i];
			g_mshell.it.i = 1;
			return (0);
		}
		(s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\f'
		&& s[i] != '\r' && s[i] != '\v') ? sym = s[i] : 0;
	}
	if (i > 1 && s[i - 1] == '|' && s[i - 2] != '\\')
		return (0);
	return (sym);
}

int			check_syntax_ex(char *s)
{
	char	sym;

	if (!check_pipes(s, ';') || !check_pipes(s, '|') || !check_pipes(s, ')') \
		|| !check_pipes(s, '>'))
		return (0);
	sym = check_syntax_extra(s);
	if (sym == '>' || sym == '<' || sym == '|')
	{
		g_mshell.it.c = sym;
		g_mshell.it.i = -1;
		return (0);
	}
	return (1);
}

int			check_syntax_prev(char *s, int i, int count)
{
	if (s[i] == '>')
	{
		count = 0;
		while (s[i++] == '>')
			count++;
		if (count > 2)
		{
			g_mshell.it.i = 1;
			g_mshell.it.c = '>';
			return (0);
		}
	}
	if (s[i] == '<')
	{
		count = 0;
		while (s[i++] == '<')
			count++;
		if (count > 3)
		{
			g_mshell.it.i = 2;
			g_mshell.it.c = '<';
			return (0);
		}
	}
	return (1);
}

int			check_syntax(char *s)
{
	int		i;
	int		count;
	int		result;

	i = -1;
	count = 0;
	while (s[++i])
	{
		result = check_syntax_prev(s, i, count);
		if (result == 0)
			return (0);
	}
	if (check_syntax_2(s))
		return (1);
	return (check_syntax_ex(s));
}
