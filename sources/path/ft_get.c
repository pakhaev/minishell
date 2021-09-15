/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:39 by cimyan            #+#    #+#             */
/*   Updated: 2021/03/09 16:08:41 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		get_quote(int *quote, int *dquote, char *c)
{
	if (!*quote && !*dquote)
	{
		*quote = 1;
		*c = 3;
	}
	else if (*quote && !*dquote)
	{
		*quote = 0;
		*c = 3;
	}
}

void		get_dquote(int *quote, int *dquote, char *c)
{
	if (!*quote && !*dquote)
	{
		*c = 3;
		*dquote = 1;
	}
	else if (!*quote && *dquote)
	{
		*c = 3;
		*dquote = 0;
	}
}

void		get_letter(int quote, int dquote, char *c)
{
	if ((quote || dquote) && *c == ' ')
		*c = 1;
	if ((quote || dquote) && *c == ';')
		*c = 2;
	if (quote && *c == '$')
		*c = 4;
	if ((quote || dquote) && *c == '|')
		*c = 5;
	if ((quote || dquote) && *c == '>')
		*c = 7;
	if ((quote || dquote) && *c == '<')
		*c = 8;
}

void		get_output(int way, t_msg *msg, char *arg)
{
	int		fd;
	int		flag;

	flag = (way == 1) ?
		O_WRONLY | O_CREAT | O_TRUNC : O_WRONLY | O_CREAT | O_APPEND;
	((fd = open(arg, flag, 0666)) < 0) ?\
	ft_show_error(2, arg) : add_output(msg->out, fd);
}

void		get_input(t_msg *msg, char *str)
{
	int		fd;

	((fd = open(str, O_RDONLY)) < 0) ? ft_show_error(4, str) : 0;
	enter_status(1);
	msg->in = fd;
}
