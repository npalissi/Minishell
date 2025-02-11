/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/10 18:32:52 by npalissi         ###   ########.fr       */
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

#define HOMEMADE	1
#define CMD			2
#define MAX_PWD		2000

#define DQUOTE		'"'
#define QUOTE		'\''

typedef struct s_sort
{
	int pos;
	int value;
	char *str;
}	t_sort;


typedef struct s_cmd
{	
	char **cmd;
	char *path;
}	t_cmd;


typedef struct s_data
{
	char	**env;
	char	*pwd;
	char **paths;
	t_cmd	*cmd_list;
	int		exit;
}		t_data;

char **create_tpwd(char *pwd);
int reload_pwd(t_data *data);
int cd(t_data *data, t_cmd *cmd);
void    collect_data(t_data *data);
void	clear_data(t_data data);
int	error_exit(t_data data, int sig, char *name);
void	fill_line_data(t_data *data, char *line);
void    signal_handler(int sig);
void    cmd_env(t_data data);
void    echo(char **cmd);
char *replace_var_env(char *str, t_data data);
char *bt_prompt(t_data data);
char **ft_arraydupe(char **tab);
char *ms_getenv(t_data data, char *key);

#endif