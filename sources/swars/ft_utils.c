/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:55:39 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/03/20 23:55:41 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				chewie_count(char *str, int i)
{
	int count;

	count = 0;
	while (str[i])
	{
		if (str[i] == '$' || str[i] == 1 || str[i] == 3)
			break ;
		if (ft_isalnum(str[i]) || str[i] == '?' || str[i] == '_')
			count++;
		i++;
	}
	return (count);
}

char			*new_chewie(char *str, char *nstr, char *arr[2], int j)
{
	int b;
	int i;

	i = 0;
	b = j + 1;
	(!(arr[1] = (char*)malloc(sizeof(char) *\
	(chewie_count(str, b) + 1)))) ? ft_error("", -1) : 0;
	while (str[b])
	{
		if (str[b] == '$' || str[b] == 1 || str[b] == 3)
			break ;
		if (ft_isalnum(str[b]) || str[b] == '?' || str[b] == '_')
		{
			arr[1][i] = str[b];
			i++;
		}
		b++;
	}
	arr[1][i] = '\0';
	if (!ft_strcmp(arr[1], arr[0]))
		str = new_str(str, nstr, j, j + ft_strlen(arr[0]) + 1);
	freed(arr[1]);
	return (str);
}
