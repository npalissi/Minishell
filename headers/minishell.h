/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/03/18 12:51:33 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_PWD 200

# define RDM_NAME	"abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTU"
# define LONG_MAX 9223372036854775807L
# define LONG_MIN (-9223372036854775807L - 1)

# define BOLD      "\033[1m"

# define RED     "\033[31m"
# define BEIGE      "\033[38;5;180m"
# define BLUE "\033[38;5;153m"
# define PINK  "\033[35m"
# define LIGHT_GRAY "\033[38;5;250m"
# define RESET   "\033[0m"

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
# include <sys/stat.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
	int		error;
}	t_cmd;

typedef struct s_data
{
	char	**env;
	char	*line;
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
int		nb_cmd(t_data data);
void	add_to_file(t_cmd cmd, int fd);
void	delete_cmd(t_data *data, int i);
void	make_exec(t_data *data);
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
void	printcmd(t_data *data); // a supp
char	*start_here_doc(t_data *data, char *lim);
void	manage_pipe(t_data *data, int pipe_fd[2]);
void	fill_data(t_data *data, char **full_line, char *line);
void	fill_command(t_data *data, char **line);
int		fill_flags(t_data *data, char **line, int i, int j);
void	fill_paths(t_data *data);
int		destroy_here_doc(t_data *data);
int		check_error(t_data *data, int i, int j, char *redir);
int		create_here_doc(t_data *data);
int		check_pipe(t_data *data, char *line);
int		create_redir(t_data *data);
void	check_all_error(t_data *data, int i, int j, int error);
int		add_error(t_data *data, int i, int *error, int error_code);
void	reset_data(t_data *data);
void	reset_data_here(t_data *data);
void	sort_cmd(t_data *data);
void	ft_strapp_off(char ***tab, char *str, int offsett);
int		check_for_cmd(t_data *data, int i);
void	child_fork(t_data *data, char *rdm_name, char *lim);
void	write_fd(int fd, char *line, char *lim, t_data *data);
char	*random_name(void);
int		keep_fd(int new_fd);
void	handle_input_redirection(t_data *data, int i, int j);
void	handle_heredoc_redirection(t_data *data, int i, int j);
void	handle_output_redirection(t_data *data, int i, int j);
void	handle_append_redirection(t_data *data, int i, int j);
void    ft_exit(t_data *data);
int make_builtin(t_data *data, int *i);

#endif