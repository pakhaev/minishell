/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:35:17 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/14 13:26:16 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *p;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = ((*lst)->next);
		(del)(p->content);
		free(p);
	}
}
