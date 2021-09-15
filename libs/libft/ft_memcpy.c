/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:17:28 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/11 15:16:12 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (dst || src)
	{
		while (n)
		{
			*d = *s;
			++d;
			++s;
			n--;
		}
		return (dst);
	}
	return (NULL);
}
