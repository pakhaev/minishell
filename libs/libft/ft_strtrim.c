/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:24:40 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/14 14:35:15 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_leftright(char const *s1, char const *set, int r)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (s1[i] && i == t)
	{
		r = 0;
		while (s1[i] != set[r] && set[r])
			r++;
		if (set[r] != '\0')
			t++;
		i++;
	}
	return (t);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		r;
	int		e;
	int		len;
	int		h;

	e = 0;
	r = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	h = ft_leftright(s1, set, r);
	len = (int)ft_strlen(s1) - 1;
	e = len;
	while (&s1[len] != s1 && len == e)
	{
		r = 0;
		while (s1[len] != set[r] && set[r])
			r++;
		if (set[r] != '\0')
			e--;
		len--;
	}
	return (ft_substr(s1, h, (e - h + 1)));
}
