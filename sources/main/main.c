/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:25:17 by cimyan            #+#    #+#             */
/*   Updated: 2021/02/24 15:25:19 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			check_syntax_2(char *s)
{
	int i;

	i = -1;
	if (ft_strchr(s, '<') && red_count(s) < 2)
	{
		while (s[++i] != '<')
			;
		if (s[i + 1] == '|' || s[i + 1] == ';' || !s[i + 2])
			;
		else if (s[i + 1] != '|' || s[i + 1] != ';' || s[i + 2])
			return (1);
	}
	return (0);
}

void		show_shell(void)
{
	ft_putstr_fd(CYAN, 2);
	ft_putstr_fd(BOLD, 2);
	ft_putstr_fd("bash-3.2$ ", 2);
	ft_putstr_fd(RESET, 2);
}

char		**dublicate_env(char **envp)
{
	char	**nstr;

	g_mshell.it.i = -1;
	if (!(nstr =\
	(char **)malloc(sizeof(char *) * ft_dstrlen(envp) + 1)))
		ft_error("dublicate_env 1", -1);
	while (envp[++g_mshell.it.i])
		(!(nstr[g_mshell.it.i] = ft_strdup(envp[g_mshell.it.i]))) \
		? ft_error("dublicate_env 2", -1) : 0;
	nstr[g_mshell.it.i] = NULL;
	return (nstr);
}

void		let_the_force_be_with_you(void)
{
	ft_putstr_fd(YELLOW, 2);
	ft_putstr_fd(BOLD, 2);
	ft_putstr_fd("\n    Episode XVI\n", 2);
	ft_putstr_fd("     MINISHELL\n", 2);
	ft_putstr_fd("Rvoltigo and Cimyan\n", 2);
	ft_putstr_fd("      <(-_-)>\n", 2);
	ft_putstr_fd("       (| |)\n", 2);
	ft_putstr_fd("        - - \n\n", 2);
	enter_status(0);
	delete_env("_");
	g_mshell.home = get_env("HOME");
}

int			main(int ac, char **av, char **ep)
{
	char	*msg;

	(void)ac;
	(void)av;
	g_mshell.envp = dublicate_env(ep);
	let_the_force_be_with_you();
	while (1)
	{
		show_shell();
		get_signal();
		get_msg(&msg);
		parse_input(msg);
	}
	return (0);
}
