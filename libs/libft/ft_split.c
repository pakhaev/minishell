/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:12:28 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/13 18:30:57 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int			count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char		**ft_free_split(char **s)
{
	size_t		i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

static size_t	ft_len(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		count;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_count(s, c);
	if (!(arr = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		if (!(arr[i] = (char *)malloc(ft_len(s, c) + 1)))
			return (ft_free_split(arr));
		ft_strlcpy(arr[i++], s, ft_len(s, c) + 1);
		s += ft_len(s, c);
	}
	arr[i] = NULL;
	return (arr);
}
