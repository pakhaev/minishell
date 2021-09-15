/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:17:46 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:23:37 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_error(char *key, int i)
{
	ft_putstr_fd(key, 2);
	(i == -1) ? ft_putstr_fd("Malloc error\n", 2) : 0;
	exit(1);
}

void		enter_error_status(int i)
{
	(i == 1 || i == 5 || i == 6 || i == 7 || i == 12) ? enter_status(1) : 0;
	(i == 3 || i == 8) ? exit(127) : 0;
}

void		ft_putstr_spec(char *s, int fd, int flag)
{
	int	i;
	int b;

	i = 0;
	b = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == '=' && flag)
			{
				ft_putchar_fd(s[i], fd);
				ft_putchar_fd('\"', fd);
				b = 1;
			}
			else
			{
				ft_putchar_fd(s[i], fd);
				if (s[i + 1] == '\0' && b)
					ft_putchar_fd('\"', fd);
			}
			i++;
		}
	}
	return ;
}

void		ft_show_msg(int i, char *str, int flag)
{
	(i == 1 && flag == 1) ? ft_putstr_fd("declare -x ", 2) : 0;
	(i == 1) ? ft_putstr_spec(str, 2, flag) : 0;
	(i == 1) ? ft_putstr_fd("\n", 2) : 0;
}

void		ft_show_error(int i, char *str)
{
	(i == 1) ? ft_putstr_fd("bash: cd: ", 2) : 0;
	(i == 1) ? ft_putstr_fd(str, 2) : 0;
	(i == 1) ? ft_putstr_fd(": No such file or directory\n", 2) : 0;
	(i == 2) ? ft_putstr_fd("bash: syntax error near unexpected\
	token `newline'", 2) : 0;
	(i == 3) ? ft_putstr_fd("bash: ", 2) : 0;
	(i == 3) ? ft_putstr_fd(str, 2) : 0;
	(i == 3) ? ft_putstr_fd(": command not found\n", 2) : 0;
	(i == 4) ? ft_putstr_fd("bash: ", 2) : 0;
	(i == 4) ? ft_putstr_fd(str, 2) : 0;
	(i == 4) ? ft_putstr_fd(": No such file or directory\n", 2) : 0;
	(i == 5) ? ft_putstr_fd("bash: export: `", 2) : 0;
	(i == 5) ? ft_putstr_fd(str, 2) : 0;
	(i == 5) ? ft_putstr_fd("': not a valid identifier\n", 2) : 0;
	(i == 6) ? ft_putstr_fd("unset: not enough arguments\n", 2) : 0;
	(i == 7) ? ft_putstr_fd("unset: `': not a valid identifier\n", 2) : 0;
	(i == 8) ? ft_putstr_fd("env: ", 2) : 0;
	(i == 8) ? ft_putstr_fd(str, 2) : 0;
	(i == 8) ? ft_putstr_fd(": No such file or directory\n", 2) : 0;
	(i == 9) ? ft_putstr_fd("bash: exit: too many arguments\n", 2) : 0;
	(i == 10) ? ft_putstr_fd("ctrl_sl error\n", 2) : 0;
	(i == 11) ? ft_putstr_fd("ctrl_c error\n", 2) : 0;
	(i == 12) ? ft_putstr_fd("bash: cd: HOME not set\n", 2) : 0;
	enter_error_status(i);
}
