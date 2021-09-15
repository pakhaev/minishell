/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:40 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:07:43 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		get_outp_extra(int i, int way, t_msg *msg)
{
	if (way == 3)
		get_input(msg, msg->argv[i + 1]);
	else
		get_output(way, msg, msg->argv[i + 1]);
}

void		get_outp(t_msg *msg)
{
	int		i;
	int		way;

	i = msg->count - 1;
	while (i >= 0)
	{
		if ((way = this_is_the_way(0, msg->argv[i], 1)) > 0)
		{
			get_outp_extra(i, way, msg);
			freed(msg->argv[i]);
			msg->argv[i] = NULL;
			freed(msg->argv[i + 1]);
			msg->argv[i + 1] = NULL;
			i--;
		}
		i--;
	}
	rm_empty_args(msg);
}

void		init_msg_extra(t_msg *msg)
{
	msg->msg_abs = NULL;
	msg->in = 0;
	parse_first_chevron(msg);
	get_outp(msg);
	set_argc(msg);
}

void		init_msg(t_msg *msg)
{
	int		i;

	init_msg_extra(msg);
	i = -1;
	while (msg->argv[++i])
	{
		if (msg->argv[i][0] == 3 || msg->argv[i][0] == 2)
		{
			freed(msg->argv[i]);
			(!(msg->argv[i] = ft_strdup(""))) ? ft_error("init_msg", -1) : 0;
		}
	}
}

void		freed(void *str)
{
	free(str);
	str = NULL;
}
