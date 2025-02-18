/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:06 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/18 11:59:56 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void manage_exec_dir(t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (data->cmd_list[i].cmd[j])
	{
		j = 0;
		while (data->cmd_list[i].cmd[j])
		{
			if (!ft_strcmp(data->cmd_list[i].cmd[j], "<"))
				
			j++;	
		}
		i++;
	}
	data->fd_in = STDIN_FILENO;
	data->fd_out = STDOUT_FILENO;
}