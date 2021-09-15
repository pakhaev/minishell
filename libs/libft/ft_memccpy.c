/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:16:56 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/11 15:15:03 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (dst || src)
	{
		d = (unsigned char*)dst;
		s = (unsigned char*)src;
		while (n)
		{
			*d = *s;
			if (*d == (unsigned char)c)
				return ((void*)++d);
			d++;
			s++;
			n--;
		}
		return (NULL);
	}
	return (NULL);
}
