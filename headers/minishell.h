/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/25 15:23:04 by npalissi         ###   ########.fr       */
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

typedef struct s_env
{
	char *key;
	char *value;
	char *str;
	struct s_env *next;
}	t_env;

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
	char	**paths;
	t_env 	*env_list;
	t_cmd	*cmd_list;
	int		exit; //(exit() appellee ou pas)
	int		exit_status;
	int		*pids;
	int		fd_in;
	int		fd_out;
	char	**here_doc_name;
	
	int		redir_fd[2];
}	t_data;

char **create_tpwd(char *pwd);
int reload_pwd(t_data *data);
int cd(t_data *data, char **cmd);
void    collect_data(t_data *data);
void	clear_data(t_data data);
int	error_exit(t_data data, int sig, char *name);
int	fill_line_data(t_data *data, char *line);
void    signal_handler(int sig);
void    cmd_env(t_data *data);
void    echo(char **cmd);
char *replace_var_env(char *str, t_data data);
char *bt_prompt(t_data data);
char **ft_arraydupe(char **tab);
char *ms_getenv(t_data data, char *key);
char *build_var_env(char *str, t_data data);

int check_quote(char *str);
void    add_quoted_word(char **word, char **str, int *idq, int *iq);
void    add_simple_word(char **word, char **str);
char	**manage_dir(char **t, int c);
char	*dup_char(char c, int size);
void parse_cmd(t_data *data);
char	**ft_ms_split(char *str, int *quote_pb);

char** ms_split_env(char* str);
t_env *ms_new_var(t_env *list, char *key, char *value, char *str);
int ms_build_array_env(t_data *data);
t_env *ms_setup_lst_env(t_data *data, char **env);
t_env *ms_get_node_by_key(t_data *data, char *key);
int ms_edit_env_lst(t_data *data, char *key, char *value, char *str);
int ms_size_lst_env(t_data *data, int is_export);
t_env **ms_build_array_export(t_data data);
int export(t_data *data, char **cmds);
void ms_free_all_env(t_data *data);
void ms_remove_env(t_data *data, char *key);
int cmd_unset(t_data *data, char **cmds);
char *ms_get_env(t_data data, char *key);

int is_valid_char(char c);
int is_valid_key(char *str);
int get_bigger(char *str1, char *str2);
int ms_print_export(t_data data);
void ms_swap_env(t_env **a, t_env **b);
void ms_free_lst_env(t_data *data);
void ms_free_env(t_env *env);

#endif