/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:03 by cimyan            #+#    #+#             */
/*   Updated: 2020/12/28 15:53:44 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *str, int f)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (f == 1)
		while (str[i] && str[i] != '\n')
			i++;
	else
		while (str[i])
			i++;
	return (i);
}

int		ft_return(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_len((char *)s1, 0) + \
						ft_len((char *)s2, 0) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*ft_dup(char *str)
{
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_len((char*)str, 1);
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_ndup(char *str)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	j = 0;
	i = ft_len(str, 1);
	if (!str[i] || !(new = (char*)malloc(sizeof(char) * \
					((ft_len(str, 0) - i) + 1))))
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}
