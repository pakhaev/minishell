/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:04:30 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/09 16:04:32 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_msg		*parse_msg_pipe_extra(char **pipes)
{
	t_msg	*msgs;
	int		i;
	t_msg	prev;

	prev.msg = NULL;
	(!(msgs = ft_calloc(sizeof(t_msg), ft_dstrlen(pipes) + 1)))\
	? ft_error("parse_msg_pipe_extra", -1) : 0;
	i = -1;
	while (pipes[++i])
		(!ft_isspace(pipes[i])) ? msgs[i] = parse_msg(pipes[i])\
		: free(pipes[i]);
	free(pipes);
	msgs[i] = prev;
	input_output(msgs);
	return (msgs);
}

t_msg		*parse_msg_pipe(char *msg)
{
	char	**pipes;

	(!(pipes = ft_split(msg, '|'))) ? ft_error("", -1) : 0;
	free(msg);
	return (parse_msg_pipe_extra(pipes));
}

t_msg		parse_msg(char *msg)
{
	char	**pieces;
	int		i;
	t_msg	res;

	i = -1;
	while (++i < MAXOUT)
		res.out[i] = -1;
	parse_msg_extra(&pieces, msg);
	res.count = parse_msg_count(pieces, res);
	(!(res.argv = ft_calloc(i + 1, sizeof(char *)))) \
	? ft_error("parse_msg", -1) : 0;
	i = -1;
	while (pieces[++i] != NULL)
		res.argv[i] = pieces[i];
	(pieces) ? free(pieces) : 0;
	parse_msg_decrypt(res);
	init_msg(&res);
	decrypt_msg_chevrons(&res);
	return (res);
}
