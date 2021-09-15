/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:34:40 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/11 15:07:30 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *buf;

	if (lst)
	{
		if (*lst)
		{
			buf = ft_lstlast(*lst);
			buf->next = new;
		}
		else
			*lst = new;
	}
}
