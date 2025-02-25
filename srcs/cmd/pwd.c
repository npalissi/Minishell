/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:08:43 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/25 15:33:38 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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
	if (!ms_edit_env_lst(data,"PWD",ft_strdup(path),ft_buildstr("%s=%s","PWD",path)))
	{
		write(1,"1",1);
		return (0);
	}
	return (1);
}
