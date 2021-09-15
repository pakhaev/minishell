/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:09:10 by cimyan            #+#    #+#             */
/*   Updated: 2020/11/11 15:53:35 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strr(char *new)
{
	int		i;
	int		j;
	char	buff;

	i = (new[0] == '-') ? 1 : 0;
	j = ft_strlen(new) - 1;
	while (i <= j)
	{
		buff = new[i];
		new[i] = new[j];
		new[j] = buff;
		i++;
		j--;
	}
}

static int		ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (size++);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char		*ft_set_arr(char *new, int i, int size, unsigned int nbr)
{
	if (nbr == 0)
		new[i++] = 0 + '0';
	else
	{
		while (nbr != 0 && size--)
		{
			new[i] = (nbr % 10 + '0');
			nbr = nbr / 10;
			i++;
		}
	}
	new[i] = '\0';
	ft_strr(new);
	return (new);
}

char			*ft_itoa(int n)
{
	int				i;
	int				size;
	int				sign;
	char			*new;
	unsigned int	nbr;

	i = 0;
	size = ft_get_size(n);
	sign = 1;
	if (n < 0)
	{
		n = n * -1;
		sign = -1;
	}
	if (n == 0)
		size++;
	nbr = n;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	if (sign < 0)
		new[i++] = '-';
	if ((ft_set_arr(new, i, size, nbr)) == NULL)
		return (NULL);
	return (new);
}
