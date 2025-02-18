/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:06 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/18 15:59:14 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void manage_exec_dir(t_data *data)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	data->fd_in = STDIN_FILENO;
	data->fd_out = STDOUT_FILENO;
	while (data->cmd_list[i].cmd)
	{
		while (data->cmd_list[i].cmd[j])
		{
			if (ft_strcmp(data->cmd_list[i].cmd[j], "<"))
				data->fd_in = open(data->cmd_list[i].cmd[j + 1], O_RDONLY | O_WRONLY);
			else if (ft_strcmp(data->cmd_list[i].cmd[j], ">"))
				data->fd_out = open(data->cmd_list[i].cmd[j + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
			else if (ft_strcmp(data->cmd_list[i].cmd[j], ">>"))
				data->fd_out = open(data->cmd_list[i].cmd[j + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
			j++;
		}
		j = 0;
		i++;
	}
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->fd_out, STDOUT_FILENO);
}
