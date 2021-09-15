/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:47 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 15:02:48 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*remove_cites(char *str)
{
	char	**strl;
	char	*nstr;

	strl = ft_split(str, 3);
	freed(str);
	nstr = join_splits(strl);
	free_double(strl);
	return (nstr);
}

void		rm_empty_args_extra(int len, t_msg *msg)
{
	char	**as;
	int		i;
	int		j;

	(!(as = ft_calloc(len + 1, sizeof(char*)))) \
	? ft_error("rm_empty_args_extra", -1) : 0;
	j = -1;
	i = -1;
	while (++i < msg->count)
	{
		if (msg->argv[i])
			as[++j] = msg->argv[i];
	}
	freed(msg->argv);
	msg->argv = as;
}

void		rm_empty_args(t_msg *msg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < msg->count)
		j += (msg->argv[i++] != NULL);
	rm_empty_args_extra(j, msg);
}
