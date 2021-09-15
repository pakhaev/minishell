/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:17:10 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/10 18:10:46 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *ps;

	ps = s;
	while (n)
	{
		if (*ps == (char)c)
			return ((void *)ps);
		ps++;
		n--;
	}
	return (NULL);
}
