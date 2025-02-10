/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:57 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../lib/libft/libft.h"
#include "../lib/printf_fd/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
#include <fcntl.h>
# include <sys/wait.h>

#define HOMEMADE	1
#define CMD			2
#define MAX_PWD		2000



typedef struct s_cmd
{	
	char **cmd;
	char *path;
}	t_cmd;

typedef struct s_data
{
	char	**env;
	char	*pwd;
	char 	**paths;
	t_cmd	*cmd_list;
	int		exit; //(exit() appellee ou pas)
	int		exit_status;
	int	*pids;
	int fd_in;
    int fd_out;
}		t_data;

char **create_tpwd(char *pwd);
int reload_pwd(t_data *data);
int cd(t_data *data, t_cmd *cmd);
void    collect_data(t_data *data);
void	clear_data(t_data data);
int	error_exit(t_data data, int sig, char *name);
int	fill_line_data(t_data *data, char *line);
void    signal_handler(int sig);
void    cmd_env(t_data data);
void    echo(char *arg, int flag);
void    parse_cmd(t_data *data);
int nb_cmd(t_data *data);
void	add_to_file(t_cmd cmd,  int fd);
void	delete_cmd(t_data *data, int i);
void    make_exec(t_data data, char *line);	
#endif