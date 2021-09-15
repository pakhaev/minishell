/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:16:22 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:25:38 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*cur_dir_extra(char dir[MAXDIR], int len, int j)
{
	char	*str;
	int		i;

	i = 0;
	(!(str = (char*)malloc(sizeof(char) * j + 1))) \
	? ft_error("cur_dir_extra", -1) : 0;
	while (dir[++len])
		str[i++] = dir[len];
	str[i] = '\0';
	return (str);
}

char		*cur_dir(void)
{
	char	dir[MAXDIR];
	int		len;
	int		i;

	i = 0;
	getcwd(dir, MAXDIR);
	len = ft_strlen(dir) - 1;
	while (dir[--len] != '/')
		i++;
	return (cur_dir_extra(dir, len, i));
}

void		check_double_msg(char *str)
{
	int		unset;
	int		pipe;
	int		cd;
	int		pwd;
	int		echo;

	unset = 0;
	pipe = 0;
	cd = 0;
	pwd = 0;
	echo = 0;
	(ft_strnstr(str, "unset", ft_strlen(str))) ? unset = 1 : 0;
	(ft_strnstr(str, "echo", ft_strlen(str))) ? echo = 1 : 0;
	(ft_strchr(str, '|')) ? pipe = 1 : 0;
	(ft_strnstr(str, "cd", ft_strlen(str))) ? cd = 1 : 0;
	(ft_strnstr(str, "pwd", ft_strlen(str))) ? pwd = 1 : 0;
	(pipe && unset && pwd) ? g_mshell.double_status = 1 : 0;
	(pipe && unset && cd) ? g_mshell.double_status = 1 : 0;
	(pipe && echo) ? g_mshell.pipe = 1 : 0;
	(pipe && echo && pwd) ? g_mshell.double_status = 1 : 0;
	(pipe) ? g_mshell.check_pipe = 1 : 0;
}
