/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_msg_ext.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:33:01 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 18:33:02 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		parse_msg_extra(char ***pieces, char *s1)
{
	int		j;

	s1 = chewie_chewie(s1);
	s1 = ft_reparse_msg(s1);
	(!(*pieces = ft_split(s1, ' '))) ? ft_error("", -1) : 0;
	freed(s1);
	j = -1;
	while ((*pieces)[++j])
		(*pieces)[j] = remove_cites((*pieces)[j]);
}

void		update_current_space(void)
{
	char *new;

	if (g_mshell.end_command)
		(!(new = ft_strjoin("_=/usr/bin/", g_mshell.end_command))) \
		? ft_error("UPDATE", -1) : 0;
	else
		(!(new = ft_strdup("_=/bin/bash"))) ? ft_error("KEY", -1) : 0;
	add_env(new);
	(new) ? freed(new) : 0;
	(g_mshell.end_command) ? freed(g_mshell.end_command) : 0;
}
