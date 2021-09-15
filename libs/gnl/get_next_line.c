/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:40:39 by cimyan            #+#    #+#             */
/*   Updated: 2020/12/28 15:53:39 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str, char *buf)
{
	int res;

	res = 1;
	while (res != 0 && !ft_return(str))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return ((char*)-1);
		}
		buf[res] = '\0';
		str = ft_join(str, buf);
	}
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	char		*buf;
	static char	*str;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	str = ft_read(fd, str, buf);
	if (str == (char*)-1)
		return (-1);
	*line = ft_dup(str);
	str = ft_ndup(str);
	if (!str)
	{
		free(str);
		return (0);
	}
	return (1);
}
