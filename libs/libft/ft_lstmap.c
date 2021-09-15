/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:35:39 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/11 15:11:24 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_first;
	t_list	*l_new;

	if (!lst || !f)
		return (NULL);
	l_first = NULL;
	while (lst)
	{
		if (!(l_new = ft_lstnew(f(lst->content))))
		{
			l_new = l_first->next;
			ft_lstclear(&l_first, del);
			l_first = l_new;
			lst = NULL;
			return (lst);
		}
		ft_lstadd_front(&l_first, l_new);
		lst = lst->next;
	}
	return (l_first);
}
