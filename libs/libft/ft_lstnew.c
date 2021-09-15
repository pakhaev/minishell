/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:33:55 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/10 18:09:47 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*lst;

	if ((lst = (t_list*)malloc(sizeof(lst))) == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
