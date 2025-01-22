/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:49:00 by npalissi          #+#    #+#             */
/*   Updated: 2025/01/22 19:07:48 by npalissi         ###   ########.fr       */
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

#define HOMEMADE	1
#define CMD			2
#define MAX_PWD		2000



typedef struct s_cmd
{	
	char *cmd;
	char **flags;
	char *path;
	int type;
}	t_cmd;


typedef struct s_data
{
	char	**argv;
	int		argc;
	char	**env;
	char	**t_pwd;
	char	*pwd;

}		t_data;

char **create_tpwd(char *pwd);
int reload_pwd(t_data *data);
void free_array(char **array);
int cd(t_data *data, t_cmd *cmd);
#endif