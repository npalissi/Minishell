/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/20 20:03:38 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_PWD 200

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"
# include "../lib/printf_fd/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}	t_cmd;

typedef struct s_data
{
	char	**env;
	char	*pwd;
	char	**paths;
	t_cmd	*cmd_list;
	int		exit; //(exit() appellee ou pas)
	int		exit_status;
	int		*pids;
	int		fd_in;
	int		fd_out;
	char	**here_doc_name;
	
	int		redir_fd[2];
}	t_data;

char	**create_tpwd(char *pwd);
int		reload_pwd(t_data *data);
int		cd(t_data *data, t_cmd *cmd);
void	collect_data(t_data *data);
void	clear_data(t_data data);
int		error_exit(t_data data, int sig, char *name);
int		fill_line_data(t_data *data, char *line);
void	signal_handler(int sig);
void	cmd_env(t_data data);
void	echo(char *arg, int flag);
void	parse_cmd(t_data *data);
int		nb_cmd(t_data *data);
void	add_to_file(t_cmd cmd, int fd);
void	delete_cmd(t_data *data, int i);
void	make_exec(t_data data, char *line);
void	check_exec_error(t_data data);
int		check_quote(char *str);
void	add_quoted_word(char **word, char **str, int *idq, int *iq);
void	add_simple_word(char **word, char **str);
void	make_split(char **t, int i[2], int index[2], char ***tab);
char	**make_dir_split(char **t, int i[2], int index[2], int iq[2]);
char	**manage_dir(char **t, int c);
void	next_w(char **str, int *iq, int *idq);
char	**split(char *word, int idq, int iq, char *str);
char	*dup_char(char c, int size);
char	**ft_ms_split(char *str, int *quote_pb);
void	manage_exec_dir(t_data *data, int i);
void	printcmd(t_data *data);
char	*start_here_doc(t_data *data, char *lim);
void	manage_pipe(t_data *data, int pipe_fd[2]);
void	fill_data(t_data *data, char **full_line, char *line);
void	fill_command(t_data *data, char **line);
int		fill_flags(t_data *data, char **line, int i, int j);
void	fill_paths(t_data *data);
int	destroy_here_doc(t_data *data);
int	check_error(t_data *data, int i, int j, char *redir);
int		create_here_doc(t_data *data);
int		check_pipe(t_data *data, char *line);

#endif