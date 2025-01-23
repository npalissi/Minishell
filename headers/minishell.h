/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/01/23 15:04:12 by edubois-         ###   ########.fr       */
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

#define HOMEMADE	1
#define CMD			2
#define MAX_PWD		2000



typedef struct s_cmd
{	
	char **cmd;
	char *path;
	int type;
}	t_cmd;


typedef struct s_data
{
	char	**argv;
	int		argc;
	char	**env;
	char	*pwd;
	char **paths;
	t_cmd	*cmd_list;
}		t_data;

char **create_tpwd(char *pwd);
int reload_pwd(t_data *data);
void free_array(char **array);
int cd(t_data *data, t_cmd *cmd);
void    collect_data(t_data *data);
void	clear_data(t_data data);
int	error_exit(t_data data, int sig, char *name);


#endif