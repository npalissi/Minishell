/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:08:43 by npalissi          #+#    #+#             */
/*   Updated: 2025/01/23 12:19:14 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char **create_tpwd(char *pwd)
{
	char **t_pwd;
	t_pwd = ft_split(pwd, '/');
	if (t_pwd)
		return (0);
	return (t_pwd);
}

int reload_pwd(t_data *data)
{
	int		size;
	char	*buffer;	
	char 	*path;

	size = 0;
	while (size < MAX_PWD)
	{
		size += 100;
		buffer = ft_calloc(size,1);
		if(!buffer)
			return (0);
		path = getcwd(buffer, size);
		if (!path && errno == ERANGE)
		{
			free(buffer);
			continue;
		}
		else
			break;
	}
	if (data->pwd)
		free(data->pwd);
	data->pwd = path;
	// if (data->t_pwd)
	return (1);
}