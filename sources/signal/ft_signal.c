/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:16:02 by rvoltigo          #+#    #+#             */
/*   Updated: 2021/02/24 15:25:58 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		sig_ctrl_c(int signal)
{
	if (g_mshell.pid)
	{
		kill(g_mshell.pid, signal);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("\b\b  \b\b", 2);
		ft_putstr_fd("\n", 2);
		enter_status(1);
		show_shell();
	}
}

void		sig_ctrl_sl(int signal)
{
	if (g_mshell.pid)
	{
		kill(g_mshell.pid, signal);
		enter_status(131);
		ft_putstr_fd("Quit: ", 2);
		ft_putnbr_fd(signal, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_putstr_fd("\b\b  \b\b", 2);
}

void		get_signal(void)
{
	void	*sig_quit;
	void	*sig_int;

	sig_int = signal(SIGINT, &sig_ctrl_c);
	sig_quit = signal(SIGQUIT, &sig_ctrl_sl);
	(sig_quit == SIG_ERR) ? ft_show_error(10, "") : 0;
	(sig_int == SIG_ERR) ? ft_show_error(11, "") : 0;
}
