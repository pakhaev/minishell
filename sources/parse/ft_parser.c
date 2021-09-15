/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:21 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:08:25 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			parse_msg_count(char **pieces, t_msg res)
{
	res.count = 0;
	while (pieces[res.count] != NULL)
		res.count++;
	return (res.count);
}

void		parse_msg_decrypt(t_msg res)
{
	int		i;

	i = -1;
	while (res.argv[++i])
		decrypt_msg(res.argv[i]);
}

char		*parser_input_extra(char *input)
{
	char	*str;

	str = NULL;
	if (ft_strnstr(input, "$0", ft_strlen(input)))
		str = ft_add_bash(input);
	g_mshell.double_status = 0;
	check_double_msg(input);
	enter_msg(input);
	return (str) ? chewie_we_are_home(str) : chewie_we_are_home(input);
}

void		parse_input(char *str)
{
	char	**commands;
	int		i;
	int		j;
	t_msg	*msgs;
	char	*input;

	msgs = NULL;
	g_mshell.phantom_menace = 0;
	input = parser_input_extra(str);
	if (!check_syntax(input))
	{
		quit_error(input, 0);
		return ;
	}
	(!(commands = ft_split(input, ';'))) ? ft_error("", -1) : 0;
	i = 0;
	j = 0;
	freed(input);
	parse_input_extended(msgs, commands, i, j);
	freed(commands);
}

int			ft_equal_issign(char *str, int flag)
{
	int		i;

	i = -1;
	if (!ft_strlen(str) || (str[0] >= '0' && str[0] <= '9') || str[0] == '?')
		return (-1);
	while (str[++i])
		if ((str[i] == '=' && (!flag || i == 0))\
		|| str[i] == ' ' || str[i] == '+')
			return (-1);
		else if (flag)
			return (1);
	return (0);
}
