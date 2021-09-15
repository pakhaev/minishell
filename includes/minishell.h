/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:23:57 by cimyan            #+#    #+#             */
/*   Updated: 2021/02/24 14:58:49 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include "colors.h"

# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define MAXOUT 4096
# define MAXDIR 1024

typedef struct	s_msg
{
	char		**argv;
	char		*msg_abs;
	char		*msg;
	int			out[MAXOUT];
	int			count;
	int			in;
}				t_msg;

typedef	struct	s_iterator
{
	int			i;
	int			j;
	int			k;
	char		c;
}				t_iterator;

typedef struct	s_mshell
{
	pid_t			pid;
	char			**envp;
	char			*home;
	int				status;
	int				double_status;
	int				pipe;
	int				check_pipe;
	char			*end_command;
	int				phantom_menace;
	int				redirect;
	char			*last;
	int				ctd;
	t_iterator		it;
}				t_mshell;

t_mshell		g_mshell;

void			ft_show_cd_extra(int flag);
void			sort(char **str);
void			ft_show_env_extra(int flag);
void			ft_show_export_extra(t_msg msg);
void			ft_show_unset_extra(t_msg msg);

void			ft_show_cd(t_msg msg);
void			ft_show_echo(t_msg msg);
void			ft_show_pwd(void);
void			ft_show_env(t_msg msg, int flag);

int				builtin(t_msg msg);
int				builtin_parent(t_msg msg);
void			ft_show_export(t_msg msg);
void			ft_show_unset(t_msg msg);
void			ft_exit(t_msg msg);

void			enter_status(int nb);
char			**add_env_extra(char *var);
void			add_env(char *str);
char			**delete_env_extra(int pos);
void			delete_env(char *str);

char			*ft_add_bash_extra(char *msg, int count);
char			*ft_add_bash(char *msg);
char			*add_env_sign(char *str, char *s1, char *s2);

char			*get_env_extra(char *val);
char			*get_env(char *var);
int				get_env_index_extra(char *val);
int				get_env_index(char *var);

void			ft_error(char *key, int i);
void			enter_error_status(int i);
void			ft_show_msg(int i, char *str, int flag);
void			ft_show_error(int i, char *str);

int				ft_check_quit(t_msg msg);
void			quit_error(char *str, int flag);
void			quit(int nbr, int status);

char			*remove_cites(char *str);
void			rm_empty_args_extra(int len, t_msg *msg);
void			rm_empty_args(t_msg *msg);

int				exec_msg(t_msg msg);
void			exec_msg_helper_extra(void);
void			exec_msg_helper(void);
void			set_argc(t_msg *msg);
void			set_escape(char *msg, int i, char c, int *flag);

char			*ft_strcat(char *s1, char *s2);
int				ft_isspace(char *str);
void			free_double(char **splits);
void			free_msg(t_msg msg);
int				red_count(char *str);

int				ft_dstrlen(char **arr);
char			*rethrow(char **str, int len);
char			*join_splits(char **strs);
int				ft_strcmp(const char *s1, const char *s2);
void			come_to_the_darkside(char *file_name, char **paths);

int				parse_first_chevron_extra(t_msg *msg);
void			parse_first_chevron(t_msg *msg);
void			parse_msg_extra(char ***pieces, char *msg);
int				ft_count_space(char *str);

void			decrypt_msg_chevrons(t_msg *msg);
void			decrypt_msg(char *str);
void			get_msg(char **buf);
void			enter_msg(char *msg);

t_msg			*parse_msg_pipe_extra(char **pipes);
t_msg			*parse_msg_pipe(char *msg);
t_msg			parse_msg(char *msg);

char			**parse_msg_extra_ext(char *msg);
char			**parse_msg_extra_ext2(char *str);
char			**parse_msg_extra_ext3(char *str);
char			**parse_msg_extra_ext4(char *str, char *msg);
void			parse_msg_extra(char ***pieces, char *msg);

int				ft_equal_issign(char *str, int flag);
int				ft_is_double_char(char *s, int i, char sym);
int				check_pipes(char *s, char c);
char			check_syntax_extra(char *s);
int				check_syntax(char *s);

int				parse_msg_count(char **pieces, t_msg res);
void			parse_msg_decrypt(t_msg res);
char			*parser_input_extra(char *input);
void			parse_input(char *str);

int				ft_reparse_msg_flag(char *msg, int i);
char			*ft_reparse_msg_extra(char *msg, char *str, int k, int i);
char			*ft_reparse_msg(char *msg);
void			parse_input_extended(t_msg *msgs, \
char **commands, int i, int j);
void			update_current_space(void);

char			*cur_dir_extra(char dir[MAXDIR], int len, int j);
char			*cur_dir(void);
void			check_double_msg(char *str);

void			get_quote(int *quote, int *dquote, char *c);
void			get_dquote(int *quote, int *dquote, char *c);
void			get_letter(int quote, int dquote, char *c);
void			get_output(int way, t_msg *msg, char *arg);
void			get_input(t_msg *msg, char *str);

int				input_output_extra(t_msg *msgs);
void			add_output_io_extra(int i, int result, t_msg *msgs);
void			input_output(t_msg *msgs);
void			add_output(int *fds, int fd);
void			ft_dupclose(t_msg msg, int flag);

char			*use_the_force_luke(char *path, char *msg);
char			*get_path_extra(char **paths, char *s2, char *msg);
char			*get_path(char *msg);
char			*get_relative_path(char *msg);
int				this_is_the_way(int *i, char *sym, int flag);

void			sig_ctrl_c(int signal);
void			sig_ctrl_sl(int signal);
void			get_signal(void);

int				ft_esc_backsl(int i, char *cmd, int quote, int dquote);
char			*new_str(char *str, char *key, int a, int b);

char			*chewie_chewie(char *str);
char			*chewie_we_are_home(char *str);
char			*return_father_luke(char **split, char *str);
char			*luke_i_am_your_father(char *str);

void			get_outp_extra(int i, int way, t_msg *msg);
void			get_outp(t_msg *msg);
void			init_msg_extra(t_msg *msg);
void			init_msg(t_msg *msg);
void			freed(void *str);

void			show_shell(void);
char			**dublicate_env(char **envp);
void			let_the_force_be_with_you(void);
int				main(int ac, char **av, char **ep);
int				check_syntax_2(char *s);

int				chewie_count(char *str, int i);
char			*new_chewie(char *str, char *nstr, char *arr[2], int j);

#endif
